#include <bits/stdc++.h>

using namespace std;

struct Town{
	int cost = 0;
};

struct City{
	int cmin_cost = 100000000;
	Town con;
	bool usetown = false;
//	City connect;
	void updatec(City to,int cost){
		if(cost < cmin_cost){
			usetown = false;
			cmin_cost = cost;
//			connect = to;
		}
	}
	void updatet(Town to,int cost){
		if(cost < cmin_cost){
			usetown = true;
			cmin_cost = cost;
		}
	}
};

int main(){

	freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	City d;
	vector<City> carray;
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++){
		carray.push_back(d);
	}
	int u,v,w;
	for(int i = 0; i < m;i++){
		cin >> u >> v >>w;
		carray[u].updatec(carray[v],w);
		carray[v].updatec(carray[u],w);
	}
	
	return 0;
} 
