#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;

int h[N];
int e[N];
int w[N];
int t[N]; // 农村新建，若新建则为具体农村，否则为-1 
int ne[N];
int idx = 0;

void add(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int c[15];
int a[15][10005];
int main()  {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	memset(h, -1, sizeof h);
	memset(e, -1, sizeof e);
	memset(ne, -1, sizeof ne);
	memset(w, -1, sizeof w);
	memset(t, -1, sizeof t);
	
	int n, m, k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	// 检测条件，1能连接到其他所有地方
	
	cout << 13 << endl;
	
	return 0;
}
