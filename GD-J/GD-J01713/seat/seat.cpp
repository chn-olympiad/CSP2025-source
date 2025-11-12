#include <bits/stdc++.h>
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
const int N = 105;
int n,m;
int t;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	t=a[1]=read();
	for (int i = 2; i <= n*m; i++) a[i]=read();
	sort(a+1,a+n*m+1);
	int x=1,y=1;
	for (int i = n*m; i >= 1; i--)
	{
		if (a[i]==t)
		{
			writech(y,' ');
			write(x);
			break;
		}
		if (y%2==1)
		{
			x++;
			if (x>n) x--,y++;
		}
		else
		{
			x--;
			if (x<1) x++,y++;
		}
	}
	return 0;
}

