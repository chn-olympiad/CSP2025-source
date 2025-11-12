#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct city{
	vector<pair<int,long long>> eg;
}ka[10010];
long long INF=1e12;
int a[10010];
struct tree{
	long long dis;
	int id;
	bool ine;
}ta[10010],tm[10010];
bool cmp(tree x,tree y){
	if(x.ine)
		return false;
	if(y.ine)
		return true;
	if(x.dis==y.dis)
		return x.id<y.id;
	return x.dis<y.dis;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ka[u].eg.push_back(make_pair(v,w));
		ka[v].eg.push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
			cin>>a[j];
		for(int u=1;u<=n-1;u++){
			for(int v=u+1;v<=n;v++){
				ka[u].eg.push_back(make_pair(v,a[u]+a[v]+c));
				ka[v].eg.push_back(make_pair(u,a[u]+a[v]+c));
			}
		}
	}
	for(int i=1;i<=n;i++){
		ta[i].dis=INF;
		ta[i].id=i;
		ta[i].ine=false;
	}
	ta[1].dis=0;
	ta[1].ine=true;
	for(int i=0;i<ka[1].eg.size();i++){
		ta[ka[1].eg[i].first].dis=min(ka[1].eg[i].second,ta[ka[1].eg[i].first].dis);
	}
	unsigned long long sum=0;
	for(int i=2;i<=n;i++){
		for(int i=1;i<=n;i++)
			tm[i]=ta[i];
		sort(tm+1,tm+n+1,cmp);
		tree tp=tm[1];
		ta[tp.id].ine=true;
		sum+=ta[tp.id].dis;
		for(int i=0;i<ka[tp.id].eg.size();i++){
			ta[ka[tp.id].eg[i].first].dis=min(ka[tp.id].eg[i].second,ta[ka[tp.id].eg[i].first].dis);
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
