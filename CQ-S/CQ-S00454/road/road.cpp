#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10020,M=2e6+5,K=11;
const ll inf=(ll)1e16;
int n,m,k,f[N],len,c[K];
bool vis[K];
ll ans;
struct node{
	int u,v;
	ll w;
	bool operator < (node aa) const{
		return w<aa.w;
	}
}a[M],b[M];
int getfa(int x){
	if(f[x]==x)return x;
	return f[x]=getfa(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			a[++m]=node{n+i+1,j,x};
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(a[i].u>n){
			b[++len]=a[i];
			continue;
		}
		int x=getfa(a[i].u),y=getfa(a[i].v);
		if(x!=y){
			f[x]=y;b[++len]=a[i];
		}
	}
	int s=(1<<k)-1;
	ans=inf;
	for(int i=0;i<=s;i++){
		ll res=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				vis[j]=1;res+=c[j];
			}
			else{
				vis[j]=0;
			}
		}
		for(int j=1;j<=n+k;j++){
			f[j]=j;
		}
		int cnt=0,need=n+(__builtin_popcount(i))-1;
		for(int j=1;j<=len;j++){
			if((b[j].u>n)&&(!vis[b[j].u-n-1]))continue;
			int x=getfa(b[j].u),y=getfa(b[j].v);
			if(x!=y){
				f[x]=y;
				res+=b[j].w;
				cnt++;if(cnt==need)break;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
