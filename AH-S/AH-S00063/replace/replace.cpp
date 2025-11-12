#include <bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int n,q;
string s[200005][2];
int kmp[5000005],f1[5000005],f2[5000005],pre[5000005],suf[5000005];
void pp(string a,string b,int op)
{
	int la = a.size(),lb = b.size();
	int j = 0;
	a = ' ' + a,b = ' ' + b;
	for (int i = 1;i <= lb;i++) kmp[i] = 0;
	for (int i = 1;i <= lb;i++)
	{
		while (j && b[i] != b[j + 1]) j = kmp[j];
		kmp[i] = j;
		if (b[i] == b[j + 1]) j++;
	}
	j = 0;
	for (int i = 1;i <= la;i++)
	{
		while (j && a[i] != b[j + 1]) j = kmp[j];
		if (a[i] == b[j + 1]) j++;
		if (j == lb)
		{
			if (op == 1) f1[i - lb + 1]++;
			else f2[i - lb + 1]++;
			j = kmp[j];
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	cin >> n >> q;
	for (int i = 1;i <= n;i++) cin >> s[i][0] >> s[i][1];
	while (q--)
	{
		string t1,t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << "0\n";
			continue;
		}
		pre[0] = 1;
		for (int i = 1;i <= t1.size();i++) pre[i] = pre[i - 1] & (t1[i] == t2[i]);
		int qwq = t1.size();
		suf[qwq + 1] = 1;
		for (int i = t1.size();i >= 1;i--) suf[i] = suf[i + 1] & (t1[i] == t2[i]);
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			if (t1.size() >= s[i][0].size())
			{

				int now = s[i][0].size();
				for (int j = 1;j <= t1.size();j++) f1[j] = f2[j] = 0;
				pp(t1,s[i][0],1); pp(t2,s[i][1],2);
				cout << "PP:" << i << '\n';
				for (int j = 1;j <= t1.size();j++)
				{
					cout << f1[j] << ' ' << f2[j] << '\n';
					if (f1[j] && f2[j] && pre[j - 1] && suf[j + now]) 
					{
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
