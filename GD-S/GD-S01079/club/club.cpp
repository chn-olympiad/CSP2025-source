#include<bits/stdc++.h>
using namespace std;
int t,n,a[114514],b[114514],c[114514],d[114514],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		ans=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			d[j]=0;
			d[j]=max(max(a[j],b[j]),max(b[j],c[j]));
			ans+=d[j];
		}
		cout<<ans<<" ";
	}
	return 0;
} 
