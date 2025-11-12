#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[1000], a ,g;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m;
	g = n*m;
	for(int i(1); i <= n *m; ++i)
	{
		cin >> A[i];
		if(i == 1)
			a = A[i];
	}
	sort(A, A+n*m+1);
	for(int i1(1); i1 <= m; ++i1)
	{
		if(i1 % 2 == 0)
		{
			for(int i(n); i >= 1; --i)
			{
				if(A[g] == a)return cout << i1 << ' ' << i, 0;
				g--;
			}
		}
		else
		{
			for(int i(1); i <= n; ++i)
			{
				if(A[g] == a)return cout << i1 << ' ' << i, 0;
				g--;
			}
		}
	}
	return 0;
} 	
