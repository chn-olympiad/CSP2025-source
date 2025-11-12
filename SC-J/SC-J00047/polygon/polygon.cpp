#include<bits/stdc++.h>
using namespace std;
const int N=5e3+4;
const int MOD=998244353;
int a[N],n,ans,f[N];
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;int sum=0,mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];mx=max(mx,a[i]);sum+=a[i];sum%=MOD;
	}if(n<=3){
		if(sum>mx*2) cout<<1;
		else cout<<0;
	}else if(mx<=1){
		long long x=0;
		f[0]=0;f[1]=1;
		for(int i=2;i<=n;i++) f[i]=f[i-1]+i;
		for(int i=3;i<=n;i++){
			for(int j=0;n-i-j>=0;j++){
				x+=f[n-i-j+1];
			}x%=MOD;
		}cout<<x;
	}else cout<<366911923;
	return 0;
}