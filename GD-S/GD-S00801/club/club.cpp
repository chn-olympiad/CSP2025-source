#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn][3];
struct cmp{
	bool operator()(array<int,2> x,array<int,2> y){
		return x[1] > y[1];
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		unsigned val = n >> 1;
		priority_queue<array<int,2>,vector<array<int,2>>,cmp> pq[3];
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",a[i],a[i]+1,a[i]+2);
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2])pq[0].push({i,a[i][0] - max(a[i][1],a[i][2])});
			else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2])pq[1].push({i,a[i][1] - max(a[i][0],a[i][2])});
			else pq[2].push({i,a[i][2] - max(a[i][1],a[i][0])});
		}
		while(pq[0].size() > val){
			int i = pq[0].top()[0];
			pq[0].pop();
			if(a[i][1] >= a[i][2])pq[1].push({i,a[i][1] - a[i][2]});
			else pq[2].push({i,a[i][2] - a[i][1]});
		}
		while(pq[1].size() > val){
			int i = pq[1].top()[0];
			pq[1].pop();
			if(a[i][0] >= a[i][2])pq[0].push({i,a[i][0] - a[i][2]});
			else pq[2].push({i,a[i][2] - a[i][0]});
		}
		while(pq[2].size() > val){
			int i = pq[2].top()[0];
			pq[2].pop();
			if(a[i][1] >= a[i][0])pq[1].push({i,a[i][1] - a[i][0]});
			else pq[0].push({i,a[i][0] - a[i][1]});
		}
		long long ans = 0;
		while(!pq[0].empty()){
			ans += a[pq[0].top()[0]][0];
			pq[0].pop();
		}
		while(!pq[1].empty()){
			ans += a[pq[1].top()[0]][1];
			pq[1].pop();
		}
		while(!pq[2].empty()){
			ans += a[pq[2].top()[0]][2];
			pq[2].pop();
		}
		printf("%lld\n",ans);
	}
} 
