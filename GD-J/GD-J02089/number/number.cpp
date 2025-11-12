#include<bits/stdc++.h>
using namespace std;
#define int long long

string in;
string s;

signed main()
{
	ifstream cin("number.in");
	ofstream cout("number.out");
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> in;
	for (int i = 9; i >= 0; --i)
	{
		for (int j = 0; j < in.size(); ++j)
		{
			if (in[j] == '0' + i)
			{
				cout << i;
			}
		}
	}
	cout << '\n';
}
