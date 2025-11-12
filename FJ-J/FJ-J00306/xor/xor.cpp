#include<bits/stdc++.h>
using namespace std;
int n,k,s[500005],ans=0,l=0,r=0;
int p(int a,int b){
	if(a==b){
		return s[a];
	}
	else{
		int f=s[a];
		for (int i=a+1;i<=b;i++){
			f^=s[i];
		}
		return f;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	for (l=0;l<=n-1;l++){
		for (r=l;r<=n-1;r++){
			if (p(l,r)>k) break;
			if(p(l,r)==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;

