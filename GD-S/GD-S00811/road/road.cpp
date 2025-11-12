#include <bits/stdc++.h>
using namespace std;
const int N=1e6+20;
int n,m,k,pr[20],d[N];
long long ans;
vector <pair<int,int> >vt;
void bfs(){
	queue <pair<int,int> > p;
	p.push({1,0});
	while (!p.empty()){
		int f=p.front().first;
		int s=p.front().second;
		p.pop();
		int mn=0x3f3f3f3f,adp=0;//add point
		for (auto&point:vt[f]){
			int ff=point.first;
			int ss=point.second;
			if (ss<mn&&ff<=n||ss+p[ff]<mn&&ff>n){
				mn=ss;
				adp=ff;
			}
		}
		ans+=mn;
		if (adp>n) ans+=pr[adp-n];
		p.push({adp,mn});
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int u,v,ww;
		scanf("%d%d",&u,&v,&ww);
		vt[u]={v,ww};
		vt[v]={u,ww};
	}
	for (int i=1;i<=k;i++){
		cin>>pr[i];
		for (int j=1;j<=n;j++){
			int ww;
			cin>>ww;
			vt[j]={n+i,ww};
		}
	}
	bfs();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
