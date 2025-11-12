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
const int N = 5e5+5,M = 1.1e6+5;
int n,k;
int a[N],sum[N];
struct xx{int t=0;vector<int> a;} ma[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	ma[0].a.push_back(0);
	for (int i = 1; i <= n; i++) a[i]=read(),sum[i]=sum[i-1]^a[i],ma[sum[i]].a.push_back(i);
	int last = 0,ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = sum[i]^k;
		while (ma[t].t<ma[t].a.size()&&ma[t].a[ma[t].t]<last&&ma[t].a[ma[t].t+1]<i) ma[t].t++;
		if (ma[t].t<ma[t].a.size()&&ma[t].a[ma[t].t]>=last&&ma[t].a[ma[t].t]<i) ans++,last=i;
	}
	write(ans);
	return 0;
}

