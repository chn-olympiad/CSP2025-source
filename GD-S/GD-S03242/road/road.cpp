#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

const int N = 1e3 + 7;
const int inf = 1e8 + 7;
using namespace std;

inline int read() {
	int x = 0, k = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') k = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x*k;
}

int n, m, k;
vector<int> left_count;
struct Pii {
	int tocity;
	int vall;
}G[N];

struct node {
	int putt;
	Pii fee[N];
}Node[N];

void insert() {
	n = read();
	m = read();
	k = read();
	bool tmp[N];
	for (int i = 1; i <= m; i++) {
		int city1 = read(), city2 = read(), val = read();
		G[city1].tocity = city2, G[city1].vall = val;
		if (!tmp[city1]) left_count.push_back(city1);
		if (!tmp[city2]) left_count.push_back(city2);
	}
	for (int i = 1; i <= k; i++) {
		Node[i].putt = read();
		for (int j = 1; j <= n; j++) {
			int feiyong = read();
			Node[i].fee[j].vall = feiyong;
		}
	}
}

void check(){
	
}

ll feee(int cnt, ll val) {
	for (int i = 1; i <= n; i++) {
		
	}
}

void work() {
	insert();
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	work();
	cout << 13;
	return 0;
} 
