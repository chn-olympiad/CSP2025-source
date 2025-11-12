#include<bits/stdc++.h>
using namespace std;
long long n,a[500020],i,j,s,u,k;
struct node
{
	long long l,r;
}b[500020];
void d(long long h,long long r,long long ss)
{
	if(h==u+1)
	{
		s=max(s,ss);
		return ;
	}
	if(r<b[h].l)d(h+1,b[h].r,ss+1);
	d(h+1,r,ss);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	for(i=1;i<=n;i++)for(j=i;j<=n;j++)
	{
		s=a[j]^a[i-1];
		if(s==k)
		{
			b[++u].l=i;
			b[u].r=j;
		}
	}
	s=0;
	d(1,0,0);
	cout<<s;
	return 0;
}