#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=5e3+5,qwq=998244353;
ll n,a[N],ans,c[N][N],jl,sd,s[N];
bool pd=1;
void dfs(ll q,bool ls){
	if(q>=n)return;
	sd+=ls;
	if(ls)jl+=a[q];
	if(ls&&jl>a[q]*2&&sd>2)
		ans++,ans%=qwq;
	dfs(q+1,true);
	dfs(q+1,false);
	if(ls)jl-=a[q];
	sd-=ls;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>a[i],pd&=(a[i]==1);
	if(pd){
		c[0][1]=1;
		for(ll i=1;i<N;i++)
			for(ll j=1;j<=i;j++)
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%qwq;
		sort(a,a+n);
		for(ll bs=n;bs>=3;bs--)
			ans=(ans+c[n+1][bs+1])%qwq;
		cout<<ans;
	}
	if(n==3){
		sort(a,a+3);
		if(a[0]+a[1]>a[2]) cout<<1;
		else cout<<0; 
	}
	else{
		sort(a,a+n);
		dfs(0,false);
		dfs(0,1);
		cout<<ans%qwq;
	}
	return 0;
}