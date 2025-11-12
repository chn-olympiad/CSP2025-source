#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;int sum = 0;
	for(int i = 1;i <= m;i++){
		int a,b,c;cin >> a >> b >> c;
		sum += c;
	}
	cout << sum;
	return 0;
}
