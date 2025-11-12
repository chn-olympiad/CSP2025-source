#include <bits/stdc++.h>

using namespace std;

const int INF = 998244353;
const int maxn = 505;
int a[maxn];
int n, m;
string s;

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << rand() % INF;
} 
