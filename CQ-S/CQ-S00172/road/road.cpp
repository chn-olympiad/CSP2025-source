//48-56-64-72?pts
//chu shu ju yao liang xin a qwqwqwqwq 
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+111;
long long ans=0x3f3f3f3f3f3f3f3f;
int n,m,k;
vector<pair<int,int> >g[N];
int a[17][N],b[N];
int dis[N];
bool ff[N];
priority_queue<pair<int,int> >q;
long long prim(int thi){
	q.push(make_pair(0,1));
	int cnt=0;
	long long ssuumm=0;
	long long sum=0;
	for(int i=n+1;i<=n+k;i++){
		if(((thi>>(i-n-1))&1)==1){
			sum+=b[i-n];
			ssuumm+=b[i-n];
		}
	}
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(ssuumm>=ans){
			return 0x3f3f3f3f3f3f3f3f;
		}
		if(cnt==n){
			break;
		}
		if(ff[u]){
			continue;
		}
		ssuumm+=dis[u];
		ff[u]=1;
		cnt++;
//		printf("%d|%d %d\n",thi,u,dis[u]);
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			if(v>n&&((thi>>(v-n-1))&1)==0){
				continue;
			}
			int len=g[u][i].second;
			if(ff[v]){
				continue;
			}
			if(dis[v]<=len){
				continue;
			}
			dis[v]=len;
			q.push(make_pair(-dis[v],v));
		}
	}
	for(int i=1;i<=n+k;i++){
		if(i>n){
			if(((thi>>(i-n-1))&1)==0){
				continue;
			}
		}
		sum+=dis[i];
		dis[i]=0x3f3f3f3f;
		ff[i]=0;
	}
	dis[1]=0;
//	printf("|%lld\n",sum);
	return sum;
}
int main(){
	srand(time(0));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		dis[i]=0x3f3f3f3f;
	}
	dis[1]=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	int p=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
		if(b[i]==0){
			p|=(1<<(i-1));
		}
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			g[n+i].push_back(make_pair(j,a[i][j]));
			g[j].push_back(make_pair(n+i,a[i][j]));
		}
	}
	for(int i=0;i<(1<<k);i++){
		if((i&p)!=p){
			continue;
		}
		ans=min(ans,prim(i));
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
