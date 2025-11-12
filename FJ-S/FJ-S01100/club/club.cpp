#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Node
{
	int p1,p2,p3;
}a[N];
int t,n,b[N],c[N],d[N],e[N];
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int x=0,y=0,z=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].p1,&a[i].p2,&a[i].p3);
			ans+=max({a[i].p1,a[i].p2,a[i].p3});
			if(a[i].p1>=a[i].p2&&a[i].p1>=a[i].p3) x++,b[x]=i;
			else if(a[i].p2>=a[i].p1&&a[i].p2>=a[i].p3) y++,c[y]=i;
			else z++,d[z]=i;
		}
		if(x>n/2)
		{
			for(int i=1;i<=x;i++)
			e[i]=min(a[b[i]].p1-a[b[i]].p2,a[b[i]].p1-a[b[i]].p3);
			sort(e+1,e+x+1);
			for(int i=1;i<=x-n/2;i++)
			ans-=e[i];
		}
		else if(y>n/2)
		{
			for(int i=1;i<=y;i++)
			e[i]=min(a[c[i]].p2-a[c[i]].p1,a[c[i]].p2-a[c[i]].p3);
			sort(e+1,e+y+1);
			for(int i=1;i<=y-n/2;i++)
			ans-=e[i];
		}
		else if(z>n/2)
		{
			for(int i=1;i<=z;i++)
			e[i]=min(a[d[i]].p3-a[d[i]].p2,a[d[i]].p3-a[d[i]].p1);
			sort(e+1,e+z+1);
			for(int i=1;i<=z-n/2;i++)
			ans-=e[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

