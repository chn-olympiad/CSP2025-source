#include<bits/stdc++.h>
using namespace std;
struct road{
	int start,end,cost;
	bool remove;
}mi[1000005];
int n,m,k,a,b,c;
typedef long long ll;
ll costs=0,crcost=0,mincost;
bool cmp(road _a,road _b){
	return _a.cost>_b.cost;
}
void remove_roads(){
	for(int i=0;i<m;i++){
		if(mi[i].start>1&&mi[i].end>1&&!mi[i].remove){
			mi[i].remove=1;
			crcost-=mi[i].cost;
			mincost=min(mincost,(ll)mi[i].cost);
			remove_roads();
			mi[i].remove=0;
			crcost+=mi[i].cost;
		}
	}
}
int bt[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		mi[i].start=min(a,b);
		mi[i].end=max(a,b);
		bt[mi[i].start]++;
		bt[mi[i].end]++;
		mi[i].cost=c;
		costs+=c;
		crcost+=c;
		mincost+=c;
	}sort(mi,mi+m,cmp);
	remove_roads();
	cout<<mincost;
}
