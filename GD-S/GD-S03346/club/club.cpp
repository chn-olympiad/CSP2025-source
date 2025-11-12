#include<bits/stdc++.h>
using namespace std;
int fi[50010],se[50010],th[50010];
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;scanf("%d",&t);
	while(t--)
	{
		int ans=0,a=0,ad=0,b=0,bd=0,c=0,cd=0;
		scanf("%d",&n);
		for(int i=1,x,y,z;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(x>y&&x>=z)fi[++a]=x;
			else if(y>=x&&y>z)se[++b]=y;
			else if(z>=y&&z>x)th[++c]=z;
		}
		sort(fi+1,fi+a+1,cmp);
		sort(se+1,se+b+1,cmp);
		sort(th+1,th+c+1,cmp);
		for(int i=1;i<=a;i++)
		{
			if(i>n/2)break;
			ans+=fi[i];
		}
		for(int i=1;i<=b;i++)
		{
			if(i>n/2)break;
			ans+=se[i];
		}
		for(int i=1;i<=c;i++)
		{
			if(i>n/2)break;
			ans+=th[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
