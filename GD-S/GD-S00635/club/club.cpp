#include<bits/stdc++.h> 
using namespace std;
int t,n,ans,sz[5];
struct Node
{
	int a,b,c,ma,m;
}a[100010];
bool cmp(Node a,Node b)
{
	return max(a.a,max(a.b,a.c))>max(b.b,max(b.a,b.c));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("clun.out","w",stdout);
	cin>>t;
	
	while(t--)
	{
		ans=0;
		cin>>n;
		if(n==2)//5pts
		{
			for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
			int a1=a[1].a,a2=a[1].b,a3=a[1].c;
			int b1=a[2].a,b2=a[2].b,b3=a[2].c;
			ans=max(a1+b2,max(a1+b3,max(a2+b1,max(a2+b3,max(a3+b1,a3+b2)))));
			cout<<ans<<endl;
			continue;
		}
		if(n==4)
		{
			for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].ma=max(a[i].a,max(a[i].b,a[i].c));
			if(max(a[i].a,max(a[i].b,a[i].c))==a[i].a)a[i].m=1;
			if(max(a[i].a,max(a[i].b,a[i].c))==a[i].b)a[i].m=2;
			if(max(a[i].a,max(a[i].b,a[i].c))==a[i].c)a[i].m=3;
		}
		for(int i=1;i<=n;i++)
		{
			if(sz[a[i].m]<=n/2)ans+=a[i].ma;
			else
			{
				
			}
			
		}
		cout<<ans;
	}
	return 0;
}
