#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e6+5;
ll f[10050];
ll find(ll x){
	if(x==f[x])return x;
	return find(f[x]);
}
void judge(ll a,ll b){
	ll fa=find(a),fb=find(b);
	if(fa==fb)return;
	f[b]=fb,f[fb]=a;
}
ll n,m,k,u[M],v[M],w[M],c[M],a[10005],ans=LLONG_MAX;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		ll cnt=0,f_c=0,k[n+50];
		memset(k,0,sizeof(k));
		for(int j=1;j<=n;j++)f[j]=j;
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[j];
		for(int j=1;j<=m;j++){
			if(k[f[v[j]]])continue;
			ll p1=w[j],p2=c[i]+a[u[j]]+a[v[j]];
			if(f_c)p2-=c[i];
			if(p2<p1){
				f_c=1,cnt+=p2;
				judge(u[j],n+i),judge(v[j],n+i);
				if(f[n+i]==f[u[j]])cnt-=a[u[j]];
				if(f[n+i]==f[v[j]])cnt-=a[v[j]];
			}
			else cnt+=p1,judge(u[j],v[j]);
			k[f[v[j]]]=1;
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}

