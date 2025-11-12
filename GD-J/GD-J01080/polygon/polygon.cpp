#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000000],b[1000000],n,m,j,k,l,c,d,x,y,ans,sum;
main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;

	for(int i=1;i<=n;i++)cin>>a[i],y+=a[i];
	sort(a+1,a+n+1);
	b[++k]=a[1];
	b[++k]=a[2];
	b[++k]=a[1]+a[2];
	for(int i=3;i<=n;i++)
	{
		ans=0;
		for(int j=1;j<=k;j++)
		{
			if(b[j]>a[i])ans++;
		}
		sum+=ans;
		l=k;
		
		for(int j=1;j<=k;j++)
	    {
	    	b[++l]=b[j]+a[i];
		}
		k=l;
		b[++k]=a[i];
	}
	cout<<sum;
} 

