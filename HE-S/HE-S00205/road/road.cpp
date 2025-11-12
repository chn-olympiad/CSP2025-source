#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespacem std;
struct twins{
	int key;
	int value;
};
vector<twins> vec[10000+5];
int flag[10000];
int dijstl(){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	for(int i = 1;i<=n;i++){
		cin>>u>>v>>w;
		vec[u].pushback({v,w});//经过后此路径为零->最短路 
		vec[v].pushback({u,w});
	}
	
	for(int i = 1;i<=m;i++){
		cin>>c;
		for(int j = 1;j<=n;j++){//费用仅一次及时删 
			cin>>w;
			vec[j].pushback({n+i,w+c});//conduct+w
			vec[n+i].pushback({j,w});
		}
	}
	djstl();
	cout<<0;
	retrun 0;
}
