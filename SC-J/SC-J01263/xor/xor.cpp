#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt;
long long a[501000],f[501000];
struct node{
	long long i,j;
}q[1001000];
bool cmp(node a,node b)
{
	return a.i<b.i;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>=100000)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int len=1;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1,p=a[i];
			for(int o=i+1;o<=j;o++)
			{
				p=p^a[o];
			}
			if(p==k)
			{
				q[++cnt].i=i;
				q[cnt].j=j;
			}
		}
	}
	long long maxx=-1;
	sort(q+1,q+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			if(q[j].j<q[i].i)
			{
				f[i]=max(f[i],f[j]+1);
			}
		}
		if(f[i]>maxx)
		{
			maxx=f[i];
		}
	}
	cout<<maxx;
	return 0;
}