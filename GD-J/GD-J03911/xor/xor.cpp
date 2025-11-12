#include <bits/stdc++.h>
using namespace std;
int n,a[10001],sum[10001][10001],x,k,top,num;
struct S
{
	int i,j;
}pos[10001];
bool cmp(S a,S b)
{
	if(a.i==b.i)
		return a.j<b.j;
	return a.i<b.i;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		sum[1][i]=a[i];
		sum[1][i]^=sum[1][i-1];
		if (a[i]==k)
		{
			num++;
			pos[++top].i=1,pos[top].j=i;
		}
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			sum[i][j]=sum[1][j]^sum[1][i-1];
			if (sum[i][j]==k)
			{
				cout <<i<<" "<<j<<endl;
				pos[++top].i=i,pos[top].j=j;
			}
		}
	}
	sort(pos+1,pos+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		if (pos[i].i>pos[i-1].j)
			num++;
	}
	cout <<num;
	return 0;
}
