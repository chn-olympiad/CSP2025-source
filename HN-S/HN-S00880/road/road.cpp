#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

const int N = 1e4+5,M = 1e6+1;
int n,m,k;//原有的城市数量-n         道路数量-m          准备进行城市化改造的乡镇数量-k
//int u[M],v[M],w[M];//第i条道路连接的两座城市-u,v                     修复该道路的费用-w
int c[15],a[15][N];//第j个乡镇进行城市化改造的费用-c     在该乡镇与原有的城市间建造道路的费用 -a
struct node{
	int c;
	int tr;
};
vector<node> v[M];

int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	int u1,u2,w;
	for(int i = 1;i <= m;i++){
		cin >> u1 >> u2 >> w;
		v[u1].push_back({u2,w});
		v[u2].push_back({u1,w});
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	
	
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
