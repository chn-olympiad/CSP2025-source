#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,y,m,x,a[100005];
int ans=0,num=0,sum=0,aum=0;
void node()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>m>>x>>y;
	}
	if(n==2||n==4)
	{
		if(n==2)
		{
			for(int i=1; i<=n; i++)
			{
				a[1]=a[i];
				ans=max(x,y);
				ans=max(ans,m);
				a[2]=a[i];
				num=max(x,y);
				num=max(num,m);
				ans=ans+num;
			}
		}
		if(n==4)
		{
			for(int i=1; i<=n; i++)
			{
				a[1]=a[i];
				ans=max(x,y);
				ans=max(ans,m);
				a[2]=a[i];
				num=max(x,y);
				num=max(num,m);
				a[3]=a[i];
				sum=max(x,y);
				sum=max(sum,m);
				a[4]=a[i];
				aum=max(x,y);
				aum=max(aum,m);
				ans=ans+num+aum+sum;
			}
		}
	}
	cout<<ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) node();
	return 0;
}
