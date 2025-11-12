#include <bits/stdc++.h>

const int N = 5e6 + 7; 

int t, q;
int ch1[N][3], ch2[N][3];

using namespace std;

string s1, s2, t1, t2;

int main ()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout); 
	scanf ("%d %d", &t, &q);
	for (int j = 1; j <= t; j ++)
	{
		cin >> s1 >> s2;
		for (int i = 0; i < s1.size (); i ++)
			if (s1[i] == 'b')
			{
				ch1[j][0] = i;
				ch1[j][1] = i + 1;
				ch1[j][2] = s1.size () - i - 1;
				break;
			}
		for (int i = 0; i < s2.size (); i ++)
			if (s2[i] == 'b')
			{
				ch2[j][0] = i;
				ch2[j][1] = i + 1;
				ch2[j][2] = s2.size () - i - 1;
				break;
			}
	}
	while (q --)
	{
		cin >> t1 >> t2;
		int b1, b2;
		int f1, f2;
		int r1, r2;
		for (int i = 0; i < t1.size (); i ++)
			if (t1[i] == 'b')
			{
				f1 = i;
				b1 = i + 1;
				r1 = t1.size () - i - 1;
				break;
			}
		for (int i = 0; i < t2.size (); i ++)
			if (t2[i] == 'b')
			{
				f2 = i;
				b2 = i + 1;
				r2 = t2.size () - i - 1;
				break;
			}
		int ans = 0;
		for (int i = 1; i <= t; i ++)
			if (f1 >= ch1[i][0] && r1 >= ch1[i][2] && b2 - b1 == ch2[i][1] - ch1[i][1])
				ans ++;
		printf ("%d\n", ans);
	}
}
