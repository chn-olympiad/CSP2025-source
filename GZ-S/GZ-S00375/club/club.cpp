//遵义四中 GZ-S00375 肖宇建 
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int ind;
	int arr[3];
}; 
struct Solution{
	int lenlimit;
	vector<Node> nodes;
	vector<vector<int> > rank;
	long long basesum;
	Solution(int n){
		basesum=0;
		lenlimit = n/2;
		rank.resize(n,vector<int>(3));
		nodes.resize(n);
		for (int i = 0; i < n; ++ i){
			scanf("%d",&nodes[i].arr[0],&nodes[i].arr[1],&nodes[i].arr[2]);
			nodes[i].ind = i;
		}

		//初始化rank
		for (int i = 0; i < n; ++ i){
			int a=nodes[i].arr[0],b=nodes[i].arr[1],c=nodes[i].arr[2];
			if (a>=b&&b>=c){
				rank[i][0] = 0, rank[i][1] = 1, rank[i][2] = 2;
				continue;
			}
			if (a>=c&&c>=b){
				rank[i][0] = 0, rank[i][1] = 2, rank[i][2] = 1;
				continue;
			}
			if (b>=a&&a>=c){
				rank[i][0] = 1, rank[i][1] = 0, rank[i][2] = 2;
				continue;
			}
			if (b>=c&&c>=a){
				rank[i][0] = 1, rank[i][1] = 2, rank[i][2] = 0;
				continue;
			}
			if (c>=a&&a>=b){
				rank[i][0] = 2, rank[i][1] = 0, rank[i][2] = 1;
				continue;
			}
			if (c>=b&&b>=a){
				rank[i][0] = 2, rank[i][1] = 1, rank[i][2] = 0;
				continue; 
			} 
		}
		for (int i = 0; i < n; ++ i){
			int mincnt = rank[i][2];
			int value = nodes[i].arr[mincnt];
			for (int j = 0; j < 3; ++ j){
				nodes[i].arr[j] -= value;
				basesum += value;
			}
			
		} 
		
	}
	void solve(){
		int total[3] = {};
		int none;
		sort(nodes.begin(),nodes.end(),[&none](Node& u, Node& v){
			int ui = u.ind, vi = v.ind;
			return u.arr[rank[ui][0]]>v.arr[rank[vi][0]];
		});
		for (int i = 0; i < n; ++ i){
			int x = rank[i][0];
			basesum += nodes[i].arr[x];
			total[x] += 1;
			if (total)
		}
	}
};
int main(){
	int test; cin >> test;
	while(test--){
		int n; cin >> n;
		Solution S(n);
		S.solve();
	} 
} 
