#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _sg string
#define lb(x) (x&(-x))
#define mak(a,b) {a,b}
#define fi first
#define se second
ll rd(){
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
ll const N=1e3+10;
ll n,k;
ll a[N];
ll sum[N][N];
ll cf[N];
ll f[N];
vector<pair<ll,ll> > v;
void add(int x,int y){
	for(;x<=n;x+=lb(x))f[x]+=y;
}
ll _sum(int l,int r){
	int ans1=0,ans2=0;
	for(int i=r;i>=1;i-=lb(i))ans1+=f[i];
	for(int i=l;i>=1;i-=lb(i))ans2+=f[i];
	return ans1-ans2;
}
ll ma=-142857,a0,mn,ans;
void dfs(int now,ll dep){
	if(now>=mn){
		ans=max(ans,dep);
		return;
	}
	ll l=v[now].fi;
	ll r=v[now].se;
	if(_sum(l,r)==0){
		for(int i=l;i<=r;i++)
			add(i,1);
		dfs(now+1,dep+1);
		for(int i=l;i<=r;i++)
			add(i,-1);
	}
	dfs(now+1,dep);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=rd();
	k=rd();
	for(int i=1;i<=n;i++){
		a[i]=rd();ma=max(a[i],ma);
		a0+=(a[i]==0);
	}
	if(ma==1){
		if(k==1){
			cout<<n-a0;
			return 0;
		}else{
			cout<<a0;
			return 0;
		}
	}
	;
	for(int i=1;i<=n;i++){
		sum[i][i]=a[i];
		if(sum[i][i]==k)
			v.push_back(mak(i,i));
		for(int j=i+1;j<=n;j++){
			sum[i][j]=sum[i][j-1]^a[j];
			if(sum[i][j]==k)
				v.push_back(mak(i,i));
		}
	}
	mn=v.size();
	dfs(0,0);
	cout<<ans;
	return 0;
}
