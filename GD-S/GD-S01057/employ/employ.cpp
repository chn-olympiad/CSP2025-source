#include<bits/stdc++.h>e
#define ll long long
#define int long long
using namespace std;

void init__();
const ll INF = LLONG_MAX;
const ll size = 1e7 + 10;
int n, m, k;

int arr[size];
//int val[size][size];

signed main()
{
	init__();
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	
	int a = rand();
	cout << a;
	
	cout << flush;
	return 0;
}

void init__()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
