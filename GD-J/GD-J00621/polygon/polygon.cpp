#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[11];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3)
	{
		if(n==3)
		{
			if(a[1]+a[2]>a[3])
			{
				cout<<1;
			}else cout<<0;
		}else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int cnt=0,k;
			if(j+i>n)break;
			for(k=j;k<j+i;k++)
			{
				cnt+=a[k];
			}
			if(cnt>a[k])ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
