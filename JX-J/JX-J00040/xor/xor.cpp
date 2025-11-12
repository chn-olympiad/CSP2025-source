#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int l,r,n,k,a[500005],res,temp;
int sxor(int a,int b)
{
	int cnt=1;
	int c[20];
	memset(c,0,sizeof(c));
	while(a | b)
	{
		if (a%2 != b%2)
		{
			c[cnt]=1;
		}
		a>>=1;
		b>>=1;
		cnt++;
	}
	int res=0;
	for (int i=cnt-1;i>=1;i--)
	{
		res+=c[i];
		res<<=1;
	}
	return res>>1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		temp = sxor(a[i],temp);
		if (temp == k)
		{
			res++;
			temp=0;
		}
	}
	cout <<res;
	return 0;
}
