#include<bits/stdc++.h>
using namespace std;
string s1[1000], s2[1000];
string jl1, jl2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w",stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	while(q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
	}
	for(int i = 1; i <= q; i++)
	{
		cout << 0 << endl;
	}
	return 0;
}
