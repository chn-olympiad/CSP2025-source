#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,maxi=-1e9,a1[1000005],a2[1000005],a3[1000005],b1,b2,b3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			int j=max(max(maxi,a1[i]),max(a2[i],a3[i]));
			if(j==a1[i])
			{
				b1++;
			}
			else if(j==a2[i])
			{
				b2++;
			}
			else
			{
				b3++;
			}
			if(b1>n/2)
			{
				ans+=max(a2[i],a3[i]);
			}
			else if(b2>n/2)
			{
				ans+=max(a1[i],a3[i]);
			}
			else if(b3>n/2)
			{
				ans+=max(a2[i],a1[i]);
			}
			else
			{
				ans+=j;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
