#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0,maxx=-1;
	for(int len=3;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			for(int j=i;j<=i+len-1;j++)
			{
				cout<<a[j];
				sum+=a[j];
				maxx=max(maxx,a[j]);
			}
			cout<<endl;
			if(sum>(2*maxx))
			{
				cnt++;
			}
			sum=0;
			maxx=-1;
		}
	}
	printf("%d",cnt);
	return 0;
}
