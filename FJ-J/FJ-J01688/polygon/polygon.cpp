#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _sg string
inline ll rd(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll const N=5005,mod=998244353;
ll n;
ll a[N],ans,ma;
__int128 gc[5005];
void dfs(ll now,ll max,ll he,ll c,bool x){
	if(he>max*2&&c>=3&&x)ans++,ans%=mod;
	if(now>n)
		return;
	dfs(now+1,a[now],he+a[now],c+1,1);
	dfs(now+1,max,he,c,0);
}
void init11(){
	gc[0]=1;gc[1]=1;
	for(int i=2;i<=n+10;i++){
		gc[i]=(i%mod*gc[i-1]%mod)%mod;
	}
	
}
inline ll rc(int a,int b){
	return gc[b]/(gc[a]%mod*gc[b-a]%mod);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++){
		a[i]=rd();
		ma=max(ma,a[i]);
	}
	init11();
	if(ma==1){
		for(int i=2;i<=n-1;i++)
			for(int j=i;j<=n-1;j++)
				ans+=rc(i,j)%mod,ans%=mod;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,0,0);
	cout<<ans/2;
	return 0;
}
