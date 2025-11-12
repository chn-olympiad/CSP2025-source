#include <iostream>
using namespace std;
long long n,k,l,r,a[50005]={},book[50005]={},cnt,maxn=0;
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
		if (a[i]==k)
		{
			book[i]=i;
			continue;
		}
		l=a[i];
		for (int j=i+1;j<=n;j++)
		{
			l=(l^a[j]);
			if (l==k)
			{
				r=j;
				break;
			}
		}
		if (l==k)
		{
			book[i]=r;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=book[i];j++)
		{
			if (book[j] && (book[j]<book[i] || (i!=j && book[j]<=book[i])))
			{
				book[i]=0;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		for (int j=i;j<=n;j++)
		{
			if (book[j])
			{
				j=book[j];
				cnt++;
			}
		}
		maxn=max(maxn,cnt);
	}
	cout << maxn;
	return 0;
}
