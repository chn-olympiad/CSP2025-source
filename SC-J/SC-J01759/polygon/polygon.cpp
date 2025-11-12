#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll Mod=998244353;
ll n,a[5005],mx,ans;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1; ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0',ch=getchar();}
	return x*f;
}
void dfs(ll x,ll sum,ll ma,ll gs){
	if(x==n+1){
		if(gs>=3&&sum>2*ma) 
		    ans++; 
		return;
	}
	
	dfs(x+1,sum+a[x],max(ma,a[x]),gs+1);
	dfs(x+1,sum,ma,gs);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		mx=max(mx,a[i]);
	}
	if(mx==1){
		ll sum=1;
		for(int j=3;j<=n;j++){
			for(int i=n;i>j;i--)
				sum*=i;
			for(int i=1;i<=n-j;i++)
				sum/=i;
			ans=(ans+sum%Mod)%Mod;
			sum=1;
		}
		cout<<ans;
	}
	else{
		dfs(1,0,0,0);
		cout<<ans;
	}
	return 0;
}