#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,l,c1,c2,c3;
long long ans;
struct cl{
	int i,x;
}a[N],b[N],c[N];
struct node{
	int i,x;
	short y;
}d[150005];
int check(node k)
{
	if(k.y==1) return ++c1;
	if(k.y==2) return ++c2;
	return ++c3;
}
bool cmp2(cl u,cl v)
{
	return u.x>v.x;
}
bool cmp(node u,node v)
{
	if(u.i==v.i) return u.x>v.x;
	return u.i<v.i;
}
bool cmp1(node u,node v)
{
	return u.x>v.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		l=ans=0;
		c1=c2=c3=(n>>1)+1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&b[i].x,&c[i].x);
			a[i].i=b[i].i=c[i].i=i;
		}
		sort(a+1,a+n+1,cmp2);
		sort(b+1,b+n+1,cmp2);
		sort(c+1,c+n+1,cmp2);
		for(int i=1;i<=(n>>1);i++)
		{
			if(a[i].x!=0) d[++l]={a[i].i,a[i].x,1};
		}
		for(int i=1;i<=(n>>1);i++)
		{
			if(b[i].x!=0) d[++l]={b[i].i,b[i].x,2};
		}
		for(int i=1;i<=(n>>1);i++)
		{
			if(c[i].x!=0) d[++l]={c[i].i,c[i].x,3};
		}
		sort(d+1,d+l+1,cmp);
		for(int i=1;i<=l;i++)
		{
			if(d[i].i!=d[i+1].i) continue;
			if(d[i].i==d[i+1].i&&d[i].i==d[i+2].i)
			{
				short bz=0;
				if(d[i+1].y==1&&a[c2].x>0) d[i+1]={a[c2].i,a[c2].x,1};
				else if(d[i+1].y==2&&b[c2].x>0) d[i+1]={b[c2].i,b[c2].x,2};
				else if(d[i+1].y==3&&c[c2].x>0) d[i+1]={c[c2].i,c[c2].x,3};
				else bz++;
				if(bz==0) c2++;
				if(d[i+2].y==1&&a[c3].x>0)
				{
					d[i+2]={a[c3].i,a[c3].x,1};
					c3++;
				}
				else if(d[i+2].y==2&&b[c3].x>0)
				{
					d[i+2]={b[c3].i,b[c3].x,2};
					c3++;
				}
				else if(d[i+2].y==3&&c[c3].x>0)
				{
					d[i+2]={c[c3].i,c[c3].x,3};
					c3++;
				}
				else bz++;
				if(bz>=1)
				{
					if(d[i].y==1) d[i]={a[c1].i,a[c1].x,1};
					else if(d[i].y==2) d[i]={b[c1].i,b[c1].x,2};
					else d[i]={c[c1].i,c[c1].x,3};
					c1++;
				}
				if(bz==2) d[i+2]={0,0,0};
				i+=2;
			}
			else if(d[i].i==d[i+1].i)
			{
				if(d[i+1].y==1&&a[c2].x>0)
				{
					d[i+1]={a[c2].i,a[c2].x,1};
					c2++;
				}
				else if(d[i+1].y==2&&b[c2].x>0)
				{
					d[i+1]={b[c2].i,b[c2].x,2};
					c2++;
				}
				else if(d[i+1].y==3&&c[c2].x>0)
				{
					d[i+1]={c[c2].i,c[c2].x,3};
					c2++;
				}
				else
				{
					if(d[i].y==1) d[i]={a[c1].i,a[c1].x,1};
					else if(d[i].y==2) d[i]={b[c1].i,b[c1].x,2};
					else d[i]={c[c1].i,c[c1].x,3};
					c1++;
				}
				i++;
			}
		}
//		cout<<endl;
//		for(int i=1;i<=l;i++) cout<<d[i].i<<' '<<d[i].x<<' '<<d[i].y<<endl;
		if(l>n)
		{
			sort(d+1,d+l+1,cmp1);
			for(int i=1;i<=n;i++) ans+=d[i].x;
		}
		else
		{
			for(int i=1;i<=l;i++) ans+=d[i].x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
