#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll t,n,ans,a1,a2,a3,gov1,gov2,gov3,maxgov;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll o=0;o<t;o++)
	{
		cin>>n;
		maxgov=n/2;
		for(ll i=0;i<n;i++)
		{
			cin>>a1>>a2>>a3;
			if(gov1<maxgov&&gov2<maxgov&&gov3<maxgov)
			{
				ans+=max(a1,max(a2,a3));
				if(a1==max(a1,max(a2,a3)))
				{
					gov1++;
				}
				else if(a2==max(a1,max(a2,a3)))
				{
					gov2++;
				}
				else
				{
					gov3++;
				}
				continue;
			}
			else if(gov1<maxgov&&gov2<maxgov)
			{
				ans+=max(a1,a2);
				if(a1==max(a2,a3))
				{
					gov1++;
				}
				else
				{
					gov2++;
				}
				continue;
			}
			else if(gov1<maxgov&&gov3<maxgov)
			{
				ans+=max(a1,a3);
				if(a1==max(a1,a3))
				{
					gov1++;
				}
				else
				{
					gov3++;
				}
				continue;
			}
			else if(gov2<maxgov&&gov3<maxgov)
			{
				ans+=max(a2,a3);
				if(a2==max(a2,a3))
				{
					gov2++;
				}
				else
				{
					gov3++;
				}
				continue;
			}
		}
		cout<<ans<<"\n";
		gov1=0;
		gov2=0;
		gov3=0;
		ans=0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
