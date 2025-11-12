#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=1e5+11;
#define ll long long
struct node{
	ll u,v,w;
}p[N];
ll tot=0,ans=1e17;
ll n,m,k,a[12][M];
int f[N];
inline int findx(int x){
	if(f[x]!=x)f[x]=findx(f[x]);
	return f[x];
}
int dnt=m,ccnt=0,cost[M];
inline bool cmp(node &x,node &y){
	return x.w<y.w;
}
inline void kruscal(){
	sort(p+1,p+1+dnt,cmp);
	int c=0;
	for(int i=1;i<=dnt;i++){
		int fu=findx(p[i].u),fv=findx(p[i].v);
		if(fu!=fv){
			f[fu]=fv;
			c++;tot+=p[i].w;
		}
		if(c==ccnt-1)break;
		if(ans<=tot)break;
	}
	if(ccnt-1!=c)return;
	ans=min(ans,tot);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+10;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>p[i].u>>p[i].v>>p[i].w;
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++){
		dnt=m;tot=0;ccnt=n;
		for(int j=1;j<=n+10;j++)f[j]=j;
		for(int j=0;j<k;j++){//必须包含这个点的最小生成树 
			if(i&(1<<j)){
				for(int t=1;t<=n;t++){
					p[++dnt]={t,j+1+n,a[j+1][t]};
				}
				tot+=cost[j+1];ccnt++;//包含这个节点 
			}
			if(tot>=ans)break;
		}
		if(tot>=ans)continue;
		kruscal();
	}
	cout<<ans<<"\n";
	return 0;
}

