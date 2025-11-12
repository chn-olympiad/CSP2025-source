#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >>n;
	int a[n+1];
	long long pos=0;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int z=n;z>=1;z--)
	{
		int t=a[z]*2;
		int x=2;
		for(int m=n-z+1;m<=n-1;m++)
		{
			for(int i=m+1;i<=n-2;i++)
			{
				if(a[m]+a[i]>t)
					pos++;
			}
		}
	}
	cout <<pos;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
