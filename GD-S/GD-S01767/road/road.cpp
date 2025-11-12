#include<bits/stdc++.h>
using namespace std;

struct Node{
	int to,w;
	int type;
};

vector<Node> city[10050];
int in_[10050];
int out_[10050];

bool cmp(Node a , Node b){
	return a.w > b.w;
}

int main(){
	int n,m,k;
	cin >> n >> m >>k; //城市数量，道路数量，乡镇数量 
	
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		city[u].push_back({v,w,0});
		city[v].push_back({u,w,0});
		in_[u] ++;
		out_[u] ++;
		in_[v] ++;
		out_[v] ++;
		
	}
	for(int i =1 ;i<=k;i++){
		int w;
		cin >> w;
		for(int j = 1;j<= n;j++){
			int cost;
			cin >> cost;
			city[n+i].push_back({j , cost+w,k});
			city[j].push_back({n+i , cost+w,k}); 
			in_[n+i] ++;
			out_[n+i] ++;
			in_[j] ++;
			out_[j] ++;
		}
	}
	sort(city.begin() , city.end() ,cmp);
	
	while()
	
	return 0;
} 
