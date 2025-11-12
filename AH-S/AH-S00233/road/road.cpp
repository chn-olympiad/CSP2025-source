#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL max(LL a,LL b){
	return a>b?a:b;
}
LL min(LL a,LL b){
	return a<b?a:b;
}

struct Road {
	LL low;
	LL high;
	LL cost;
};

bool compareRoad(Road a, Road b) {
	return a.cost < b.cost;
}

int main() {

	freopen("road.in", "r", stdin);                                           
	freopen("road.out", "w", stdout);                                         
	
	LL n,m,k;
	cin>>n>>m>>k;
	vector<Road> roads(m);
	LL edges[n];
	for(LL i=0;i<n;i++) {
		edges[i] = -1;
	}
	for(LL i=0;i<m;i++) {
		LL u,v,w;
		cin>>u>>v>>w;
		roads[i].low = min(u,v) -1;
		roads[i].high = max(u,v) -1;
		roads[i].cost = w;
	}
	for(LL i=0;i<k;i++) {
		LL dontneed;cin>>dontneed;
		LL costs[n];
		for(LL j=0;j<n;j++) {
			cin>>costs[j];
		}
		for(LL j=0;j<m;j++) {
			roads[j].cost = min(roads[j].cost, costs[roads[j].low] + costs[roads[j].high]);
		}
	}
	sort(roads.begin(), roads.end(), compareRoad);
	LL count = 0;
	LL answer = 0;
	for(int i=0;count<n-1&&i<m;i++) {
		LL low = roads[i].low;
		LL high = roads[i].high;
		if(edges[low] != -1 && edges[low] == edges[high]) {
			continue;
		}
		if(edges[low] == -1) {
			if(edges[high] == -1) {
				edges[high] = edges[low] = low;
			} else edges[low] = edges[high];
		} else {
			LL edgeHigh = edges[high];
			for(LL j=0;j<n;j++) {
				if(edges[j] == edgeHigh) edges[j] = edges[low];
			}
		}
		count++;
		answer += roads[i].cost;
	}
	cout<<answer;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



