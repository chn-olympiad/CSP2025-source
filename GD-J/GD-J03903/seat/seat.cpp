//100pts
#include<bits/stdc++.h>
//bool Mst;
#define ll long long
using namespace std;
const int N = 15;
int n, m, a[N*N];
bool cmp(int a, int b){
	return a > b;
}

//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cerr << abs((&Mst)-(&Med)) / 1024.0 / 1024 << "MB" << '\n';
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i) cin >> a[i];
	int tmp = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; ++i){
		if(a[i] == tmp){
			int x = ceil(1.0 * i / n);
			int y = i - (x - 1) * n;
			if(x % 2 == 0) y = n + 1 - y;
			cout << x << ' ' << y;
			break;
		}
	}
	
	return 0;
} 
