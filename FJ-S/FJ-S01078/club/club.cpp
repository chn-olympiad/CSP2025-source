#include<bits/stdc++.h>
using namespace std;
int n,x,y,z,t,ans,k[4];
struct uuu{
	int fi;
	int se;
	int xf,xs;
}a[100000];
bool cmp(uuu xx,uuu yy)
{
	return xx.fi+yy.se>yy.fi+xx.se;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0)
	{
	ans=0;
	k[1]=0;
	k[2]=0;
	k[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x>=y&&x>=z)
		{
			a[i].fi=x;
			a[i].xf=1;
			if(y>=z)
			{
				a[i].se=y;
				a[i].xs=2;
			}
			else
			{
				a[i].se=z;
				a[i].xs=3;
			}       
		}
		else
		{
		if(y>=x&&y>=z)
		{
			a[i].fi=y;
			a[i].xf=2;
			if(x>=z)
			{
				a[i].se=x;
				a[i].xs=1;
			}
			else
			{
				a[i].se=z;
				a[i].xs=3;
			}       
		}
		else
		{
			a[i].fi=z;
			a[i].xf=3;
			if(x>=y)
			{
				a[i].se=x;
				a[i].xs=1;
			}
			else
			{
				a[i].se=y;
				a[i].xs=2;
			} 
		}
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(k[a[i].xf]<n/2)
		{
			ans+=a[i].fi;
			k[a[i].xf]+=1;
		}
		else
		{
			ans+=a[i].se;
		}
	}
	printf("%d\n",ans);
	t--;
	}
}




























