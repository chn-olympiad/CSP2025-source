#include <bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
struct Node{
	int first,second,third;
}a[Nmax];
bool cmp(Node a,Node b)
{ 
	return a.first>b.first;
}
long long t,n,ans=0,cnt=0;
int flag=1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		flag=1,ans=0,cnt=n/2;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i].first>>a[i].second>>a[i].third;
			if(a[i].second!=0||a[i].third!=0)
			{
				flag=0;
			}
		}
		sort(a+1,a+n+1,cmp);
		// for(int i=1;i<=n;i++)
		// {
		// 	printf("a[%d].first=%d\n",i,a[i].first);
		// }
		if(flag==1)
		{
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].first;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].first>a[i].third&&cnt>=1)
				{
					ans+=a[i].first;
					cnt--;
				}
				else
				{
					ans+=a[i].second;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}