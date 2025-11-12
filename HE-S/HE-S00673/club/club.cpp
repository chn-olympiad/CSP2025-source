#include <bits/stdc++.h>
using namespace std;
int n,t;
int a[200006];
int main()
{
	cin>>t;
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	while(t--)
	{
		int ans=0;
		int x,y;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>x>>y;
		}
		sort(a+1,a+n+1);
		for(int i=(n/2+1);i<=n;i++)
		{
			ans+=a[i];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
