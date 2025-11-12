#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
	int x,y,z;
}a[N];
//int aa[N],bb[N],cc[N];
bool cmp(node ax,node ay)
{
    if(ax.x!=ay.x) return ax.x>ay.x;
    else return ax.y>ay.y;
}

int T;
int ww;
int qq;
int wa;
int ans=0;
int n;
int d=0,e=0,f=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		d=0;
		e=0;
		f=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			//scanf("%d%d%d",&aa[i],&bb[i],&cc[i]);
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(d>n/2) a[i].x=0;
			if(e>n/2) a[i].y=0;
			if(f>n/2) a[i].z=0;
			ww=max(a[i].y,a[i].z);
			qq=max(a[i].x,ww);
			if(qq==a[i].x) d++;
			else if(qq==a[i].y) e++;
			else f++;
			ans+=qq;
		}
		printf("%d\n",ans);	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
