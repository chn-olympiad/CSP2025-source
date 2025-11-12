#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Student
{
	long long d1,d2,d3,dmax;
};
Student a[100005];
int t;
bool cmp(Student x,Student y)
{
	return x.d1>y.d1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].dmax=max(a[i].d1,max(a[i].d2,a[i].d3));
		}	
		if(n==2)
		{
			cout<<max(max(max(a[1].d2+a[2].d1,a[1].d3+a[2].d1),max(a[1].d1+a[2].d2,a[1].d3+a[2].d2)),max(a[1].d1+a[2].d3,a[1].d2+a[2].d3));
		}
		if(a[1].d3==0&&a[1].d2==0)
		{
			ll ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].d1;
			}
			cout<<ans;
			continue;		
		}
		/*else if(a[i].d3==0)
		{
			int ans=0;
			int f[100005];
			memset(f,0,sizeof(f));
			int c1=0,c2=0,c3=0;
		    for(int i=1,i<=n;i++)
		    {
		    	if(c1<=n/2&&c2<=n/2)
		    	{
		    		
				}
		        else if()
			}
		}*/
	}
	return 0;
}
