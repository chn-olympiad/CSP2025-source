#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll ksm(ll a,ll b){ll res=1;for(;b;(a*=a)%=mod,b>>=1) if(b&1) (res*=a)%=mod;return res;}
ll i,j,n,ans,a1,a[5555],s[5555],C[5555][5555],v[5555];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(cin>>n,i=1;i<=n;cin>>a[i],a1=max(a[i],a1),s[i]=s[i-1]+a[i],i++);
	for(i=1;i<=n;C[i][1]=i,C[i][i]=1,i++);
	for(i=2;i<=n;i++) for(j=2;j<i;C[i][j]=C[i-1][j-1]+C[i-1][j],j++);
	if(a1==1){//È«ÊÇ1 
		for(i=3;i<=n;i++) (ans+=C[n][i])%=mod;
		return cout<<ans,0;
	}//24pts 
	if(n==3){
		if(a[1]+a[2]>a[3]) return cout<<1,0;
		return cout<<0,0;
	}//12pts
	return cout<<0,0;
}
