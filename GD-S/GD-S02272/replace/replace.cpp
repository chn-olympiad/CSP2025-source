#include <bits/stdc++.h>
using namespace std;

map<string, string> ss;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		ss[s1] = s2;
	}
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		string dif1 = "", dif2 = "";
		int head = -1, tail = t1.size();
		for (int i = 0; i < t1.size(); i++)
		{
			if (t1[i] != t2[i] && head == -1) 
			{
				head = i;
			}
			if (t1[n - i] != t2[n - i] && tail == t1.size())
			{
				tail = n - i;
			}
		}
		for (int i = head; i <= tail; i++)
		{
			dif1 += t1[i]; 
			dif2 += t2[i];
		}
//		cout << head << " " << tail << endl;
//		cout << dif1 << " " << dif2 << endl << endl;
//		cout << endl;
		int cnt = 0;
		for (int a = 0; a <= head; a++)
		{
			for (int b = tail + 1; b <= t1.size(); b++)
			{
				string diff1 = "", diff2 = "";
				for (int i = head - a; i < head; i++)
				{
					diff1 += t1[i];
					diff2 += t2[i];
				}
				diff1 += dif1;
				diff2 += dif2;
				for (int i = tail + 1; i < b; i++)
				{
					diff1 += t1[i];
					diff2 += t2[i];
				}
				if (ss[diff1] == diff2) cnt++;
//				cout << diff1 << " " << diff2 << endl;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}


