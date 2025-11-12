//GZ-J00196 贵阳市花溪区剑桥学校（初中部） 戚星汉
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct stu{
	int t;
	long long v;
}h[10005][10005];
bool cmp(stu xx,stu yy){
	return xx.v<yy.v;
}
vector<stu> e[10005];
int n,m,k,a[10005],f[10005],tmp,u,vis[10005],d[10005],cnt,ans;
pair<int,int> r;
void p(){
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	priority_queue<pair<int,int> > q;
	q.push({0,1});
	while(!q.empty()){
		r=q.top();
		u=r.second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			long long w=e[u][i].v;
			int k=e[u][i].t;
			if(d[k]>d[u]+w){
				d[k]=d[u]+w;
				q.push({-w,k});
			}
		}
	}
	for(int i=2;i<=n;i++){
		ans+=d[i];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	long long w,a;
	int u,v;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&w);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a);
		}
	}
	p();
	cout<<ans;
	return 0;
} 
