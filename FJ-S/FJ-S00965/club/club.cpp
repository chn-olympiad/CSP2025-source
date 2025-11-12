#include<bits/stdc++.h>
#define cse(N) {++p.N,r+=a[i].N;continue;}
int _x(int a,int b){return a>b?a:b;}
struct M{int a,b,c;} a[100005];
bool _p(M x,M y){return _x(x.a,_x(x.b,x.c))>_x(y.a,_x(y.b,y.c));}
int dfs_ans;
void dfs(int n,int x=0,int sum=0,int ap=0,int bp=0,int cp=0)
{
	if(x==n){dfs_ans=_x(dfs_ans,sum);return;}
	if(ap<n/2)dfs(n,x+1,sum+a[x].a,ap+1,bp,cp);
	if(bp<n/2)dfs(n,x+1,sum+a[x].b,ap,bp+1,cp);
	if(cp<n/2)dfs(n,x+1,sum+a[x].c,ap,bp,cp+1);
	return;
}
int main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,r=0;
		M p= {0,0,0};
		scanf("%d",&n);
		for(int i=0; i<n; ++i)
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		if(n<=10)
		{
			dfs_ans=0;
			dfs(n);
			printf("%d\n",dfs_ans);
		}
		else
		{	
			std::sort(a,a+n,_p);
			for(int i=0; i<n; ++i)
			{
				if(a[i].a>a[i].b&&a[i].a>a[i].c&&p.a<(n>>1))cse(a)
				if(a[i].b>a[i].a&&a[i].b>a[i].c&&p.b<(n>>1))cse(b)
				if(a[i].c>a[i].a&&a[i].c>a[i].b&&p.c<(n>>1))cse(c)
				if(a[i].a==a[i].b&&a[i].b==a[i].c)
				{
					if(p.a<=p.b&&p.a<=p.c)cse(a)
					if(p.b<=p.a&&p.b<=p.c)cse(b)
					if(p.c<=p.a&&p.c<=p.b)cse(c)
				}
				if(a[i].a==a[i].b){if(p.a>=p.b)cse(b)else cse(a)}
				if(a[i].b==a[i].c){if(p.b>=p.c)cse(c)else cse(b)}
				if(a[i].a==a[i].c){if(p.a>=p.c)cse(c)else cse(a)}
				if(p.a==n/2){if(p.b>=p.c)cse(c)else cse(b)}
				if(p.b==n/2){if(p.a>=p.c)cse(c)else cse(a)}
				if(p.c==n/2){if(p.a>=p.b)cse(b)else cse(a)}
			}
			printf("%d\n",r);
		}
	}
	return 0;
}//ÉîËÑ+Ì°ĞÄ£ºWA~7/20

