#include <bits/stdc++.h>
using namespace std;

#define spc putchar(32)
#define endl putchar(10)

const int N = 5e5 + 5;

int f[N];
int n, k;
int where[1048580];

int rd()
{
	char c = getchar(); int s = 0;
	while(!isdigit(c)) c = getchar();
	do s = (s << 1) + (s << 3) + (c ^ 48), c = getchar(); while(isdigit(c));
	return s;
}

void wr(int x)
{
	if(x > 9) wr(x / 10);
	putchar(x % 10 | 48);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(where, -1, sizeof(where));
	where[0] = 0;
	n = rd(), k = rd();
	for(int i = 1, x, s = 0; i <= n; ++i)
	{
		x = rd();
		s ^= x;
		int lst = where[s ^ k];
		if(~lst) f[i] = max(f[lst] + 1, f[i-1]);
		else f[i] = f[i-1];
		where[s] = i;
	}
	wr(f[n]);
	return 0;
}
