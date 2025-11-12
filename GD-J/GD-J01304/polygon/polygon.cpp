#include <bits/stdc++.h>
using namespace std;
int n, A[10000] ,ans, w = 1;


int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n;
	for(int i(1); i <= n; ++i)
		cin >> A[i];
	if(n == 3)
	{
		if(A[1] + A[2] + A[3] > A[1]*2 && A[1] + A[2] + A[3] > A[2]*2 && A[1] + A[2] + A[3] > A[3]*2)return cout << 1, 0;
		else return cout << 0, 0;
	}

	return 0;
} 	
