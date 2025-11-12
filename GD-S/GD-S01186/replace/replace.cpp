#include<iostream>
using namespace std;

int n, q;
string s1, s2, l[200010], r[200010];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	while(q--)
	{
		cin >> s1 >> s2;
		string tot;
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < l[i].size() && j + s1.size() - 1 < l[i].size(); j++)
			{
				tot = l[i];
				for(int k = j; k < j + s1.size(); k++)
				{
					if(tot[k] != s1[k - j]) break;
//					cout << '*';
					tot[k] = s2[k - j];
				}
//				cout << tot << endl;
				if(tot == r[i])
				{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
//		cout << endl;
	}
}
