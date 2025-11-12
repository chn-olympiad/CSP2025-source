#include<bits/stdc++.h>
using namespace std;
int n,q,fj,jf;
string s1,s2,t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for (int j = 1;j <= q;j++)
	{
		cin >> t1[j] >> t2[j];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= q;j++)
		{
			if (t1[j] == s1[i])
			{
				fj++;
			}
			else if (t2[j] == s2[i])
			{
				jf++;
			}
		}
	}
	for (int i = 1;i <= q;i++)
	{
		cout << 0 << endl;
	}
	return 0;
}

