#include <bits/stdc++.h>
using namespace std;

#define spc putchar(32)
#define endl putchar(10)

int n, m, R, a1;

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
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = rd(), m = rd();
	R = 1, a1 = rd();
	m *= n;
	for(int i = 2; i <= m; ++i)
	{
		if(rd() > a1) ++R;
	}
	if(!(R % n))
	{
		int r = R / n;
		wr(r), spc;
		if(r & 1) wr(n);
		else wr(1);
	}
	else
	{
		int r = R / n + 1;
		wr(r), spc;
		if(r & 1) wr(R % n);
		else wr(n - R % n + 1);
	}
	return 0;
}
