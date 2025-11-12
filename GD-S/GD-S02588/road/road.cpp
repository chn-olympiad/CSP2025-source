#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n,m,k,w;
int mp[N],num;
int v[N],ve[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i =1 ;i <= m;i++){
		int x,y,z;
		cin >> x >> y >> w;
		mp[x] = y;
		mp[y] = x;
	} 
	for(int i = 1;i <= k;i++){
		cin >> v[i];
		for(int j = 1;j <= n;j++){
			cin >> ve[i];
			num += ve[i];
		}
	}
	cout << num;
	return 0;
}
