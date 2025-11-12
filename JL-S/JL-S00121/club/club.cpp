#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	int p1;
	int b;
	int p2;
	int c;
	int p3;
};
bool cmp(node a,node b)
{
	if(a.a>b.a) return true;
	else return false;
}
int sum[4];
long long ans;
long long ans1=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		node a[n+1];
		sum[1]=sum[2]=sum[3]=1;
		ans=0;
		bool flag1=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].p1=1;
			a[i].p2=2;
			a[i].p3=3;
			if(a[i].b!=0||a[i].c!=0) flag1=false;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].b>a[i].a)
			{
				int p=a[i].a;
				a[i].a=a[i].b;
				a[i].b=p;
				p=a[i].p1;
				a[i].p1=a[i].p2;
				a[i].p2=p;
			}
			if(a[i].c>a[i].b)
			{
				int p=a[i].b;
				a[i].b=a[i].c;
				a[i].c=p;
				p=a[i].p2;
				a[i].p2=a[i].p3;
				a[i].p3=p;
			}
			if(a[i].b>a[i].a)
			{
				int p=a[i].a;
				a[i].a=a[i].b;
				a[i].b=p;
				p=a[i].p1;
				a[i].p1=a[i].p2;
				a[i].p2=p;
			}
		}
		//meihangpaixuwanshi
		sort(a+1,a+1+n,cmp);
		if(flag1)
		{
			int sumk=0;
			for(int i=1;i<=(n/2);i++)
			{
				sumk=sumk+a[i].a;
			}
			cout<<sumk<<endl;
			continue;
		}
		/*for(int i=1;i<=n;i++)
		{
			cout<<a[i].a<<" "<<a[i].p1<<" "<<a[i].b<<" "<<a[i].p2<<" "<<a[i].c<<" "<<a[i].p3<<endl; 
		}*/
		for(int i=1;i<=n;i++)
		{
			if(sum[a[i].p1]<=(n/2))
			{
				ans=ans+a[i].a;
				sum[a[i].p1]++;
			}
			else
			{
				if(sum[a[i].p2]<=(n/2))
				{
					int cha=a[i].a-a[i].b;
					bool flat=true;
					int q=0;
					for(int j=1;j<=sum[a[i].p1];j++)
					{
						if(a[j].a-a[j].b<cha&&a[j].a!=-1)
						{
							cha=a[j].a-a[j].b;
							flat=false;
							q=j;
						}
					}
					if(flat)
					{
						ans=ans+a[i].b;
						sum[a[i].p2]++;
					}
					else
					{
						int j=q;
						ans=ans-a[j].a+a[i].a+a[j].b;
						sum[a[j].p2]++;
						a[j].a=-1;
					}
				}
				else
				{
					int cha=a[i].a-a[i].c;
					bool flat=true;
					int q=0;
					for(int j=1;j<=sum[a[i].p1];j++)
					{
						if(a[j].a-a[j].c<cha&&a[j].a!=-1)
						{
							cha=a[j].a-a[j].c;
							flat=false;
							q=j;
						}
					}
					if(flat)
					{
						ans=ans+a[i].c;
						sum[a[i].p3]++;
					}
					else
					{
						int j=q;
						ans=ans-a[j].a+a[i].a+a[j].c;
						sum[a[j].p3]++;
						a[j].a=-1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
