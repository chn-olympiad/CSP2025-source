#include<bits/stdc++.h>
using namespace std;
int a[110000];
int p[15];
int b[110000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++)
	{
		b[i] = s[i] - '0';
	}
	for(int i = 1;i <= n;i++)
	{
		p[i] = i;
		cin >> a[i];
	}
	int anss = 0;
	do
	{
		int sum = 0;
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(sum >= a[p[i]])
			{
				sum++;
			}
			else if(b[p[i]])
			{
				sum++;
			}
			else
			{
				ans++;
			}
		}
		if(ans >= m)
		{
			anss++;
		}
	}
	while(next_permutation(p + 1,p + n + 1));
	cout << anss << endl;
	return 0;
}
