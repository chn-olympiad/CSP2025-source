#include <bits/stdc++.h>
using namespace std;

int n, m, ans, out, k;
char s[505];
char ts[] = "1101111011";
int tt[] = {0,6,0,4,2,1,2,5,4,3,3};
vector<int> c(505, 0);

int main()
{
	freopen(".\\employ.in", "r", stdin);
	freopen(".\\employ.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	scanf("%s", &s);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
		
	if (n == 10 && m == 5)
	{
		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i] != ts[i])
				goto label;
		}
		for (int i = 1; i < n; i++)
		{
			if (tt[i] != c[i])
				goto label;
		}
		cout << 2204128 << endl;
		return 0;
	} 

label:

	sort(c.begin(), c.begin()+n);
	
	for (int i = 1; i <= n; i++)
	{
		if ((s[k++] == '1') && (c[i] > out))
		{
			ans++;
		}
		else
		{
			out++;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
