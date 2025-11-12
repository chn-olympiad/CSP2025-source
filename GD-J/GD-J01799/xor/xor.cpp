#include <bits/stdc++.h>
using namespace std;
int a[500005], sum=0, qzh[500005], jsq=0, k=0;
struct abc
{
	int start,lon,end;
}b[500005];
int shu=0;
bool cmp(abc &a, abc &b)
{
	if (a.end==b.end)
	{
		return a.lon<b.lon;
	}
	return a.end<b.end;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n,k;
	cin >> n >> k;
	for (int i= 1; i<= n; i++)
	{
		cin >> a[i];
		qzh[i]=qzh[i-1]^a[i];
	}
	qzh[0]=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=i; j++)
		{
			sum=qzh[i]^qzh[j-1];
			if (sum==k)
			{
				b[++shu].start=j;
				b[shu].end=i;
				b[shu].lon=i-j+1; 
			}
		}
	}
	sum=qzh[n];
	if (sum==k)
	{
		b[++shu].start=1;
		b[shu].end=n;
		b[shu].lon=n;
	}
	sort (b+1, b+shu+1, cmp);
	k=1;
	jsq++;
	k+=b[1].lon;
	int jsq2=1;
	while (jsq2<=shu)
	{
		jsq2++;
		if (b[jsq2].start<=k)
		{
			continue;
		}
		else
		{
			jsq++;
			k+=b[jsq2].lon;
		}
	}
	cout << jsq;
	return 0;
}
