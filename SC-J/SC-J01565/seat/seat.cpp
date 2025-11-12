#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, self, id = 1;
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> n >> m >> self;
	for(int i = 1; i < n * m; i++){
		int x;
		cin >> x;
		if(x > self)id++;
	}
	int r = (id - 1) / n + 1, c = (id - 1) % n + 1;
	if(r % 2 == 0)c = n - c + 1;
	cout << r << " " << c << endl;
	return 0;
}
/*
Record

2025-11-1 8:45 Pass T2

Solution
统一一下排名，列数直接算，行数分奇偶性讨论一下即可，O(n)

Note
Nothing Here 
*/ 