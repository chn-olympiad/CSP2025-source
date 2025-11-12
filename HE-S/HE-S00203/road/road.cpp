#include<bits/stdc++.h>
using namespace std;
#define N 1000005


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n, m, k;//n：城市数量   m：道路数量    k:准备改革的乡村数量 
	cin >> n >> m >> k;
	int rns[3][m];//第i条道路连接的两座城市------和修复第i条道路的费用 
	int ens[n][k]; 
	for(int i = 0;i < m;i++){
		for (int j = 0; j < 3; j++){
			cin >> rns[j][i];
		}
	}
	for(int i = 0;i i < k; i++){
		for (int j = 0; j < n; j++){
			cin >> ens[j][i];
		}
	}
	
	
}
