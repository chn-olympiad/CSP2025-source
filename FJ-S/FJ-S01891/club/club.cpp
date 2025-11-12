#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b,c,f;
}a[100005],b[100005],c[100005];
bool cmp(node x,node y)
{
	return x.f<y.f;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,u=0,v=0,w=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y,z,flag=0;
			cin>>x>>y>>z;
			int maxx=max(max(x,y),z);
			if(maxx==x)	
				flag++;
			if(maxx==y)
				flag++;
			if(maxx==z)
				flag++;
			ans+=maxx;
			if(flag==1)
			{
				if(maxx==x)
				{
					a[++u].a=x;
					a[u].b=y;
					a[u].c=z;
					a[u].f=x-max(y,z);
				}
				else if(maxx==y)
				{
					b[++v].a=x;
					b[v].b=y;
					b[v].c=z;
					b[v].f=y-max(x,z);
				}
				else{
					c[++w].a=x;
					c[w].b=y;
					c[w].c=z;
					c[w].f=z-max(x,y);
				}
			}
		}
		if(u<=n/2&&v<=n/2&&w<=n/2)
			cout<<ans<<endl;
		else{
			if(u>n/2)
			{
				sort(a+1,a+u+1,cmp);
				for(int i=1;i<=u-n/2;i++)
					ans-=a[i].f;
				cout<<ans<<endl;
			}
			else if(v>n/2)
			{
				sort(b+1,b+v+1,cmp);
				for(int i=1;i<=v-n/2;i++)
					ans-=b[i].f;
				cout<<ans<<endl;
			}
			else{
				sort(c+1,c+w+1,cmp);
				for(int i=1;i<=w-n/2;i++)
					ans-=c[i].f;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
