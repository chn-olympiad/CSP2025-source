#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t=0,n=0,a[10005][10005]={};
	cin>>t;
	for(;t>0;t--)
	{
		cin>>n;
		long long cnt=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i+=2)
		{
			cnt=max(max(a[i][1],a[i][2]),a[i][3])+max(max(a[i+1][1],a[i+1][2]),a[i+1][3]);
			ans+=cnt;	
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
