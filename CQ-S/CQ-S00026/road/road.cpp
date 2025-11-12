#include<bits/stdc++.h>
using namespace std;
const int N=10015,M=1000005;
int fa[N];
int getfa(int u){
	if(fa[u]==u) return u;
	return fa[u]=getfa(fa[u]);
}
struct node{
	int a,b,c;
}E[M];
bool cmp(node A,node B){
	return A.c<B.c;
}
vector<pair<int ,int > > vp[15];
int tot[1055];
node vec[1055][N];
int w[15];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&E[i].a,&E[i].b,&E[i].c);
	for(int i=1;i<=k;i++){
		scanf("%d",&w[i]);
		for(int j=1;j<=n;j++){
			int ww;
			scanf("%d",&ww);
			vp[i].push_back({ww,j});
		}
		sort(vp[i].begin(),vp[i].end());
	}
	sort(E+1,E+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=getfa(E[i].a),fy=getfa(E[i].b);
		if(fx!=fy){
			fa[fy]=fx;
			vec[0][++tot[0]]=E[i];
		}
	}
	for(int s=1;s<(1<<k);s++){
		int lb=0;
		for(int i=0;i<k;i++){
			if((s>>i)&1){
				lb=i;
				break;
			}
		}
		int t=s-(1<<lb);
		lb++;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int now=1;
		for(pair<int,int> pr:vp[lb]){
			int c=pr.first,a=pr.second;
			while(now<=tot[t]&&vec[t][now].c<=c){
				int fx=getfa(vec[t][now].a),fy=getfa(vec[t][now].b);
				if(fx!=fy){
					fa[fy]=fx;
					vec[s][++tot[s]]=vec[t][now];
				}
				now++;
			}
			int fx=getfa(a),fy=getfa(n+lb);
			if(fx!=fy){
				fa[fy]=fx;
				node my;
				my.a=a;my.b=n+lb;my.c=c;
				vec[s][++tot[s]]=my;
			}
		}
		while(now<=tot[t]){
			int fx=getfa(vec[t][now].a),fy=getfa(vec[t][now].b);
			if(fx!=fy){
				fa[fy]=fx;
				vec[s][++tot[s]]=vec[t][now];
			}
			now++;
		}
	}
	long long ans=1e18;
	for(int s=0;s<(1<<k);s++){
		long long sum=0;
		for(int i=0;i<k;i++)
			if((s>>i)&1) sum+=w[i+1];
		for(int i=1;i<=tot[s];i++) sum+=vec[s][i].c;
		ans=min(ans,sum);
	}
	printf("%lld",ans);
}
