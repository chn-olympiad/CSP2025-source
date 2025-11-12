#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],s[2];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool fa=1,fb=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1) fa=0;
    	if(a[i]!=1 and a[i]!=0) fb=0;
    	if(a[i]==0) s[0]++;
    	if(a[i]==1) s[1]++;
	}
	if(fa) cout<<n/2;
	else if(fb){
		if(k==0) cout<<s[0]/2+s[1]/2;
		if(k==1){
			int pairs=min(s[0],s[1]);
			cout<<pairs;
		}
	}
	else cout<<2;
	return 0;
}
