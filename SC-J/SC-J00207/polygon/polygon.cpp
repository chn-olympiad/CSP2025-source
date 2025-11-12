#include<bits/stdc++.h>
using namespace std;
int L=998244353,n,a[5050],p[5050],sum;
void q(int s,int w,int maxx)
{
	if(w>2*maxx)
	{
		sum++;
		sum=sum%L;
	}
	for(int i=s;i<=n;i++)
	{
		if(p[i]==0)
		{
			p[i]=1;
			q(i,w+a[i],max(a[i],maxx));
			p[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	q(1,0,0);
	printf("%d",sum);
	return 0;
}
