#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
using namespace std;
const int N = 1e6+5;
char s[N];
int cnt, a[N];
bool cmp(int x, int y)
{
	return x > y; 
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s",s+1);
	int len = strlen(s+1);
	For(i, 1, len)
	{
		if('0' <= s[i] && s[i] <= '9')
			a[++cnt] = s[i]-'0';
	}
	sort(a+1, a+1+cnt, cmp);
	For(i, 1, cnt)
		printf("%d",a[i]);
	return 0;
}

