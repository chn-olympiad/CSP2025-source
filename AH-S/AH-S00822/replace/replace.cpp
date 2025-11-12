#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;

const int N = 5000010;

int n, q;
int a1[N], b1[N], a2[N], b2[N];
string s1[N], s2[N];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q); bool flag = 1;
	memset(a1, -1, sizeof a1);
	memset(a2, -1, sizeof a2);
	memset(b1, -1, sizeof b1);
	memset(b2, -1, sizeof b2);
	for (int i = 1; i <= n; i ++ )
	{
		cin >> s1[i] >> s2[i];
		for (int j = 0; j < s1[i].size(); j ++ )
			if(s1[i][j] == 'b') a1[i] = j, a2[i] = s1[i].size() - 1 - j;
			else if(s1[i][j] != 'a') flag = 0;
		for (int j = 0; j < s2[i].size(); j ++ )
			if(s2[i][j] == 'b') b1[i] = j, b2[i] = s2[i].size() -1 -  j;
			else if(s2[i][j] != 'a') flag = 0;
	}
	if(!flag)
	{
		for (int i = 1; i <= q; i ++ ) puts("0");
		return 0;
	}
	while (q -- )
	{
		string t1, t2;
		cin >> t1 >> t2;
		int p1 = -1, p2 = -1;
		for (int j = 0; j < t1.size(); j ++ )
			if(t1[j] == 'b') p1 = j;
		for (int j = 0; j < t2.size(); j ++ )
			if(t2[j] == 'b') p2 = j;
		int ans = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if(p1 == -1 && a1[i] != -1) continue;
			if(p2 == -1 && b1[i] != -1) continue;
			if(p1 != -1 && a1[i] == -1) continue;
			if(p2 != -1 && b1[i] == -1) continue;
			if(p1 != -1 && p2 != -1 && a1[i] != -1 && a2[i] != -1 && p1 - p2 != a1[i] - a2[i]) continue;
			if(a1[i] > p1 || b1[i] > t1.size() - 1 - p1 || b1[i] > p2 || b2[i] > t1.size() - 1 - p2) continue;
			ans ++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
