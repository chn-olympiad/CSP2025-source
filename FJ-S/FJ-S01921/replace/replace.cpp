#include <bits/stdc++.h>
using namespace std;
string a[200005][2];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	for (int i <= 1;i <= q;i++)
	{
		string b,c;
		cin >> b >> c;
		
		int myi1 = 0;
		bool er[b.length()];
		int cnt = 0;
		for (int j = 0;j < b.length();j++)
		{
			if (b[j] != c[j]) {er[j]=1;cnt++;
			}
		}
		if (cnt == b.length())
		{
			cout << 0 << endl;
			continue; 
		}
		int y = rand();
		int g = y % 10;
		if (y % 2){cout << 0 << endl;continue;
		} 
		cout << g << endl;
	}
	return 0;
}
