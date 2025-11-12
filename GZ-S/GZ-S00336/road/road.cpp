//GZ-S00336 贵阳市第十八中学 王相宇
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000010],b[1000010],x[1000010],c[1000010],sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>x[i];	
	}	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=m;i++)
	{
		int qwq[1000010],cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i]==j||b[i]==j)qwq[cnt++]=x[i];
		}
		sort(qwq+1,qwq+cnt+1);
		sum+=qwq[1];
	}
	cout<<sum;
	return 0;
}
