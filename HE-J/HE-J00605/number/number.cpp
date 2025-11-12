#include <bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	s = " " + s;
	int t = s.size();
	int m = s.size();
	for (int i = 1;i <= t-1;i++)
	{
		int x = s[i]-'0';
		if (x < 10)
		{
			a[s[i]-'0']++;
			m--;
	    }
	}
	int z = t - m;
	for (int i = z;i >= 0;i--)
	{
		while(a[i]!=0)
		{
			a[i]--;
			cout << i;
		}
	}
    return 0;	
} 
