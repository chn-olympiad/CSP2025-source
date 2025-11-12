#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
bool s(int a,int b,int c)
{
	return((a+b)>c&&(a+c)>b)&&((b+c)>a&&(a+b+c)>max(a,max(b,c)));
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(i==j)
			continue;
			for(int s=1;s<j;s++)
			{
				if(j==s)
				continue;
				if(s)
				{
					ans++;
					}	
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		
	}
	for(int i=1;i<=n;i++)
	cout<<ans%998224353;
	return 0;
}

