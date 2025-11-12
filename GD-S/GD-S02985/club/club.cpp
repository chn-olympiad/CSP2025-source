#include<bits/stdc++.h>
using namespace std;

int t;
int a[100010][5];
struct node{
	int a1,a2,a3;
}f[100010];

bool cmp(const node &x,const node &y)
{
	return x.a1>y.a1;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==2)
		{
			int a11,a12,a13,a21,a22,a23;
			scanf("%d %d %d",&a11,&a12,&a13);
			scanf("%d %d %d",&a21,&a22,&a23);
			int ans=a11+max(a22,a23);
			ans=max(ans,a12+max(a21,a23));
			ans=max(ans,a13+max(a21,a22));
			printf("%d",ans);
		}
		else if(n==4)
		{
			int ans=-1;
			for(int i=1;i<=n;i++)
				scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			for(int A=1;A<=3;A++)
			for(int b=1;b<=3;b++)
			for(int c=1;c<=3;c++)
			for(int d=1;d<=3;d++)
			{
				if((A==b&&b==c)||(A==b&&b==d)||(A==c&&c==d)
				||(b==c&&c==d)) continue;
				ans=max(ans,a[1][A]+a[2][b]+a[3][c]+a[4][d]);
			}
			printf("%d",ans);
		}
		else if(n==10)
		{
			int ans=-1;
			int p[5]={0,0,0,0,0};
			for(int i=1;i<=n;i++)
				scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			for(int A=1;A<=3;A++)
			for(int b=1;b<=3;b++)
			for(int c=1;c<=3;c++)
			for(int d=1;d<=3;d++)
			for(int e=1;e<=3;e++)
			for(int f=1;f<=3;f++)
			for(int g=1;g<=3;g++)
			for(int h=1;h<=3;h++)
			for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				p[1]=0;p[2]=0;p[3]=0;
				p[A]++;p[b]++;p[c]++;p[d]++;p[e]++;
				p[f]++;p[g]++;p[h]++;p[i]++;p[j]++;
				if(p[1]>5||p[2]>5||p[3]>5) continue;
				ans=max(ans,a[1][A]+a[2][b]+a[3][c]+a[4][d]+
				a[5][e]+a[6][f]+a[7][g]+a[8][h]+a[9][i]+a[10][j]);
			}
			printf("%d",ans);
		}
		else{
			int ans=0;
			bool pfa=true,pfb=true;
			for(int i=1;i<=n;i++)
			{
				scanf("%d %d %d",&f[i].a1,&f[i].a2,&f[i].a3);
				if(f[i].a2!=0||f[i].a3!=0) pfa=false;
				if(f[i].a3!=0) pfb=false;
			}
			if(pfa)
			{
				sort(f+1,f+n+1,cmp);
				for(int i=1;i<=n/2;i++)
					ans+=f[i].a1;
				printf("%d",ans);
			}
			else if(pfb)
			{
				for(int i=1;i<=n;i++)
					ans+=max(f[i].a1,f[i].a2);
				printf("%d",ans);
			}
				
		}
	}
	return 0;
}
