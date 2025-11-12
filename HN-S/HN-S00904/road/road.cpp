#include<bits/stdc++.h>
#define int long long
using namespace std;
struct o{
	int x,y,z;
}k[2000005],t[2000005];
// int pd[200005],a1,a2,a3,d[200005];
int fa[100005];
int a[15][200005];
bool cmp(o a,o b){
	return a.z<b.z;
}
int find(int x){
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
int ans=LONG_LONG_MAX;
int tot=0;
int n,m,K;
int f[200005],c[205];
void dfs(int x){
	if(x==K+1){
		int sum=0;
		for(int i=1;i<=n+K;i++)fa[i]=i;
		// for(int i=1;i<=K;i++)cout<<f[i]<<" ";
		// cout<<"\n";
		for(int i=1;i<=K;i++){
			if(f[i]){
				sum+=c[i];
				if(sum>ans)return;
				// int p=find(i),q=find(i+n);
				// fa[q]=p;
			}
		}
		// cout<<sum<<"   ";
		for(int i=1;i<=tot;i++){
			int p=find(t[i].x),q=find(t[i].y);
			if(q>n){
				if(!f[q-n])continue;
			}
			if(p>n){
				if(!f[p-n])continue;
			}
			// cout<<t[i].x<<" "<<t[i].y<<" "<<t[i].z<<"\n";
			if(p!=q){
				fa[q]=p;
				sum+=t[i].z;
				if(sum>ans)return;
			}
		}
		// cout<<sum<<"\n";
		ans=min(ans,sum);
		return;
	}
	f[x]=0;
	dfs(x+1);
	f[x]=1;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	// cin>>n>>m>>K;
	scanf("%lld%lld%lld",&n,&m,&K);
	// n=1e4;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		k[i]={x,y,z};
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(k+1,k+m+1,cmp);
	for(int i=1;i<=m;i++){
		int p=find(k[i].x),q=find(k[i].y);
		if(p!=q){
			fa[q]=p;
			t[++tot]={p,q,k[i].z};
		}
	}
	for(int i=1;i<=K;i++){
		scanf("%lld",&c[i]);
		// t[++tot]={i,i+n,c[i]};
		for(int j=1;j<=n;j++){
			// cin>>a[i][j];
			scanf("%lld",&a[i][j]);
			t[++tot]={i+n,j,a[i][j]};
		}
	}
	sort(t+1,t+tot+1,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}