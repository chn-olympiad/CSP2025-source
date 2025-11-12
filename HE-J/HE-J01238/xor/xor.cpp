#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005],d[500005];
struct stu{
	int begin;
	int end;
}x[1500005];
int cmp(stu a,stu b)
{
	return a.end<b.end;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==d[i-1])
		{
			d[i]=0;
		}
		else
		{
			d[i]=1;
		}
	}
	d[1]=0;
	int f,y=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(d[i]==d[j])
			{
				f=0;
			}
			else
			{
				f=1;
			}
			if(f==k)
			{
				x[y].begin=j+1;
				x[y].end=i;
				y++;
			}
		}
	}
	sort(x,x+y+1,cmp);
	long long sum=0;
	f=1;
	for(int i=2;i<=y;i++)
	{
		if(x[i].begin>x[f].end)
		{
			sum++;
			f++;
		}
	}
	cout<<sum;
	return 0;
}
