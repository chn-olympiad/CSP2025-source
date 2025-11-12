#include<bits/stdc++.h> 
using namespace std;
int a[100001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int abc=0;
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			int cnt=0,ans=0;
			for(int w=j;w<=j+i;w++)
			{
				cnt+=a[w];
				ans=max(ans,a[w]);
			}
			if(cnt>ans*2) abc++;
		}
	}
	cout<<abc;
	return 0;
}
