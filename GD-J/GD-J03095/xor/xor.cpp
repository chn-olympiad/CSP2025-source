#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,jsq,ans,xw;
struct ddb
{
	long long l,r;
} b[500005];
bool cmp(const ddb &a,const ddb &b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==m)
		{
			b[++jsq].l=i;
			b[jsq].r=i;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(a[i]==m)
			continue;
		sum=a[i];
		for(long long j=i+1;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==m)
			{
				b[++jsq].l=i;
				b[jsq].r=j;
				break;
			}
			if(a[j]==m)
				break;
		}
	}
	sort(b+1,b+jsq+1,cmp);
	for(long long i=1;i<=jsq;i++)
		if(b[i].l>xw)
		{
			ans++;
			xw=b[i].r;
		}
	cout<<ans;
	return 0;
}
