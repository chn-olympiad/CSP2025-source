#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100005],x,y,d,cnte,add[15][100005],cost[15];
long long ans,sum;
struct edge{
	int from,to,dis;
}e[1000005];
bool operator<(edge x,edge y){
	return x.dis>y.dis;
}
int find(int x){
	if (x==a[x]) return x;
	return a[x]=find(a[x]);
}
void hb(int x,int y){
	x=find(x);
	y=find(y);
	a[x]=y;
}
void clear(){
	for (int i=1;i<=n+k;i++){
		a[i]=i;
	}
}
priority_queue<edge> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>x>>y>>d;
		q.push({x,y,d});
	}
	clear();
	while (!q.empty()){
		auto ioptre=q.top();
		q.pop();
		if (find(ioptre.from)!=find(ioptre.to)){
			hb(ioptre.from,ioptre.to);
			e[++cnte]=ioptre;
		}
	}
	ans=0x3f3f3f3f3f3f3f3f;
	for (int i=1;i<=k;i++){
		cin>>cost[i];
		for (int j=1;j<=n;j++){
			cin>>add[i][j];
		}
	}
	for (int i=0;i<(1<<k);i++){
		clear();
		for (int j=1;j<=cnte;j++){
			q.push(e[j]);
		}
		sum=0;
		for (int j=1;j<=k;j++){
			if (i&(1<<(j-1))){
				sum+=cost[j];
				for (int o=1;o<=n;o++){
					q.push({o,j+n,add[j][o]});
				}
			}
		}
		while (!q.empty()){
			auto ioptre=q.top();
			q.pop();
			if (find(ioptre.from)!=find(ioptre.to)){
				hb(ioptre.from,ioptre.to);
				sum+=ioptre.dis;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}
