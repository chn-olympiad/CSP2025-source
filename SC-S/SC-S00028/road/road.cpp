#include <bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
}a[100005];
struct v{
	int x;
	int a;
}b[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,sum = 0;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		sum += a[i].w;
	}
	for(int i = 1;i <= k;i++){
		int x,minn = 0x3f3f3f3f;
//		auto ve = vector<int>();
		cin >> x;
		for(int j = 1;j <= n;j++){
			int m;
			cin >> m;
			minn = min(minn,m);
			b[i] = {x,minn};
		}
	}
	cout << sum;
	return 0;
}