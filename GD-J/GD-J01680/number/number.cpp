#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s[N];
int cnt[20];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++)
		if('0' <= s[i] && s[i] <= '9')
			cnt[s[i]-'0']++;
	for(int i = 9; i >= 0; i--)
		while(cnt[i] > 0)
		{
			printf("%d", i);
			cnt[i]--;
		}
	return 0;
}
