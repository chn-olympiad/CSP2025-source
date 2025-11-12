//¼ÌÐøÆ­·Ö 
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 1e4 + 10; 
int n,m,k;
struct road{
	int u,v,w;
};

vector<road> build[N];
vector<road> map[N];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		map[u].push_back({v,w});
		map[v].push_back({u,w});
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
