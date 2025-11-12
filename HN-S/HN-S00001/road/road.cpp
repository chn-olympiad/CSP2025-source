#include <bits/stdc++.h>
using namespace std;

/*int youlu[10005][10005];
int youh[10005];
int yous[10005];*/


struct exist{
	int c1;
	int c2;
	int weight=1;
	int cost;
}road[1000005], roadnew[100005];

struct build{
	int cost;
	int city[10005];
}village[15];

bool smaller(struct exist a, struct exist b){
	return a.cost<b.cost;
}

int xunlu(int n, int s){
	
	
	
	
	
}

/*int bianli(int maxcost, int n ){
}*/

int main(){
	memset(youlu, 0, sizeof(youlu));
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n,m,k,anst,maxcost=0;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		cin>>road[i].c1>>road[i].c2>>road[i].cost;
	}
	for(int i=1; i<=k; i++){
		cin>>village[i].cost;
		for(int j=1; j<=n; j++){
			cin>>village[i].city[j];
		}
	}
	sort(road+1, road+m+1, smaller);
	/*for(int i=1; i<=m; i++)
		maxcost+=road[i].cost;
	int o=0;
	for(int i=1; i<=k; i++){
		maxcost+=village[i].cost;
		for(int j=1; j<=n; j++){
			maxcost+=village[i].city[j];
			o++;
			roadnew[o].c1=i+n;
			roadnew[o].c2=j;
			roadnew[o].cost=village[i].city[j];
		}
	}*/
	
	/*for(int i=1; i<=m; i++){
		youlu[road[i].c1][road[i].c2]++;
		youh[road[i].c1]++;
		yous[road[i].c2]++;
		
	}*/
	   
	for(int i=m; i>=1; i++){
		
		
	}
	
	
	return 0;
}


