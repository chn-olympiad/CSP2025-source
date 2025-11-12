#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct ct{
	int u;
	int v;
	int cost;
};
ct x[1000];
struct vg{
	int cost;
	int rd[1000];
};
vg y[1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i].cost>>x[i].u>>x[i].v;
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		cin>>y[i].cost;
		for(int j=1;j<=n;j++){
			cin>>y[i].rd[j];
		}
	}
//	for(int i=1;i<=m;i++){
//		cin>>y[i].cost;
//		for(int j=1;j<=n;j++){
//			cin>>y[i].rd[j];
//		}Elysia
/* CCF !!!? */
	return 0;
}
