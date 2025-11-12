#include <bits/stdc++.h>
using namespace std;

int n,a[10000];
long long ans;
bool cmp(int i,int j)
{
	return i>j;
}
int maxn(int q,int p)
{
	int sun=0;
	for (int i=q;i<=p;i++)
	{
		sun=max(sun,a[i]);
	}
	return sun;
}
int sum(int i,int j)
{
	int cnt=0;
	for (int k=i;k<=j;k++)
	{
		cnt+=a[k];
	}
	return cnt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if (n==3)
	{
		if (sum(1,3)>2*maxn(1,3))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
 } 