#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	if(m == 1) cout << n << endl;
	else
	{
		cout << n - m << endl;
	}
	return 0;
}
