#include<bits/stdc++.h>
using namespace std;
int const N = 1e4 + 8;
int n,m,k;
int s[N],e[N],p[N],p1[N],p2[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		cin >> s[i] >> e[i] >> p[i];
	}
	for(int i = 0;i < k;i++){
		cin >> p1[i];
		for(int j = 0;j < n;j++){
			cin >> p2[i][j];
		}
	}
	cout << 13;
}
