#include<bits/stdc++.h>
using namespace std;

int N, n, a[100004], b[100004], c[100004], d[100005];

struct Node
{
	int a, b, c;
	int sum;
}k[100004];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> n;
		int num = n / 2;
		for (int j = 1; j <= n; j++)
		{
			cin >> k[j].a >> k[j].b >> k[j].c;
		}
	}
	cout << k[1].a << k[1].b << k[1].c;
	return 0;
}
