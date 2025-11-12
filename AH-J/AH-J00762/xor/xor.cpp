#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],ans=0;
int main(){
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     cin>>n>>k;
     for(int i=1;i<=n;i++){
		 cin>>a[i];
		 if(a[i]==k){
			 ans++;
		 }
		 s[i]=(s[i-1]^a[i]);
	 }
	 int l=1,r=1;
	 while(r<=n){
		 if((s[r]^s[l-1])==k){
			 ans++;
			 r++;
		 }else if((s[r]^s[l-1])>k){
			 l++;
		 }else if((s[r]^s[l-1])<k){
			 r++;
		 }
	 }
	 cout<<ans;
     return 0;
}
