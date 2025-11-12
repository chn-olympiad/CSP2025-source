#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int a1;
	int a2;
	int a3;	
}a[1000005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int n,m;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>m;
		int u=m;
		for(int i=1;i<=m;++i)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		int ans=0;
		int t=m/2;
		int j[4]={0};
		for(int i=1;i<=m;++i)
		{
			if(a[i].a1==0&&a[i].a2==0)
			{
					for(int i=1;i<m;++i)
		{
			for(int j=i+1;j<=m;++j)
			{
				if(a[i].a3<a[j].a3)
				{
					swap(a[i].a1,a[j].a1);
					swap(a[i].a2,a[j].a2);
					swap(a[i].a3,a[j].a3);
				}
			}
		}
				if(j[3]==t&&j[1]!=t)
				{
					j[1]++;
					a[i].a3=0;
				}
				else if(j[3]==t&&j[2]!=t)
				{
					j[2]++;
					a[i].a3=0;
				}
				else
				{
				ans+=a[i].a3;
				j[3]++;
				a[i].a3=0;
				}
			}
			if(a[i].a1==0&&a[i].a3==0)
			{
				for(int i=1;i<m;++i)
		{
			for(int j=i+1;j<=m;++j)
			{
				if(a[i].a2<a[j].a2)
				{
					swap(a[i].a1,a[j].a1);
					swap(a[i].a2,a[j].a2);
					swap(a[i].a3,a[j].a3);
				}
			}
		}
				if(j[2]==t&&j[1]!=t)
				{
					j[1]++;
					a[i].a2=0;
				}
				else if(j[2]==t&&j[3]!=t)
				{
					j[3]++;
					a[i].a2=0;
				}
				else
				{
				ans+=a[i].a2;
				j[2]++;
				a[i].a2=0;
				}
			}
			if(a[i].a3==0&&a[i].a2==0)
			{
				for(int i=1;i<m;++i)
		{
			for(int j=i+1;j<=m;++j)
			{
				if(a[i].a1<a[j].a1)
				{
					swap(a[i].a1,a[j].a1);
					swap(a[i].a2,a[j].a2);
					swap(a[i].a3,a[j].a3);
				}
			}
		}
				if(j[1]==t&&j[2]!=t)
				{
					j[2]++;
					a[i].a1=0;
				}
				else if(j[1]==t&&j[3]!=t)
				{
					j[3]++;
					a[i].a1=0;
				}
				else
				{
				ans+=a[i].a1;
				j[1]++;
				a[i].a1=0;
				}
			}
		}
		for(int i=1;i<m;++i)
		{
			for(int j=i+1;j<=m;++j)
			{
				if(a[i].a1<a[j].a1)
				{
					swap(a[i].a1,a[j].a1);
					swap(a[i].a2,a[j].a2);
					swap(a[i].a3,a[j].a3);
				}
			}
		}
		for(int i=1;i<=t;++i)
		{
			if(j[1]==t&&u==0)
			{
				break;
			}
			j[1]++;
			ans+=a[i].a1;
			a[i].a1=0;
			a[1].a2=0;
			a[1].a3=0;
			--u;
		}
		for(int i=1;i<m;++i)
		{
			for(int j=i+1;j<=m;++j)
			{
				if(a[i].a2<a[j].a2)
				{
					swap(a[i].a1,a[j].a1);
					swap(a[i].a2,a[j].a2);
					swap(a[i].a3,a[j].a3);
				}
			}
		}
		for(int i=1;i<=t;++i)
		{
			if(j[2]==t&&u==0)
			{
				break;
			}
			if(a[i].a2>a[i].a3)
			{
			j[2]++;
			ans+=a[i].a2;
			a[i].a1=0;
			a[1].a2=0;
			a[1].a3=0;
			--u;
			}
		}
		for(int i=1;i<m;++i)
		{
			for(int j=i+1;j<=m;++j)
			{
				if(a[i].a3<a[j].a3)
				{
					swap(a[i].a1,a[j].a1);
					swap(a[i].a2,a[j].a2);
					swap(a[i].a3,a[j].a3);
				}
			}
		}
		for(int i=1;i<=t;++i)
		{
			if(j[3]==t&&u==0)
			{
				break;
			}
			j[3]++;
			ans+=a[i].a3;
			a[i].a1=0;
			a[1].a2=0;
			a[1].a3=0;
			u--;
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
