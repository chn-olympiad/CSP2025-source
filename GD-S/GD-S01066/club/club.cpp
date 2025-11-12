#include<bits/stdc++.h>
using namespace std;
struct qwq{ int a,b,c,t,e; }f[100010];
int g,n,aa,bb,cc,ans,l[9],r[9],js[9],ty[5][100010];
bool cmp(qwq x,qwq y)
{
	if(x.t==y.t)
	{
		if(x.a==y.a)
		{
			if(x.b==y.b) return x.c<y.c;
			return x.b<y.b;
		}
		return x.a<y.a;
	}
	return x.t<y.t;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&g);
	while(g--)
	{
		memset(js,0,sizeof(js));
		memset(ty,0,sizeof(ty));
		ans=0;
		l[1]=1,l[2]=1,l[3]=1;
		r[1]=0,r[2]=0,r[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
			f[i].t=max(f[i].a,max(f[i].b,f[i].c));
			if(f[i].t==f[i].a) f[i].e=1;
			else if(f[i].t==f[i].b) f[i].e=2;
			else f[i].e=3;
		}
		sort(f+1,f+1+n,cmp);
		int k=n/2;
		for(int i=1;i<=n;++i)
		{
			if(js[f[i].e]+1>k)
			{
				int tt=f[i].t-ty[f[i].e][l[f[i].e]];
				if(f[i].e==1)
				{
					int p=-1;
					if(f[i].b>tt)
					{
						p=f[i].b;
						js[2]++;
					}
					if(f[i].c>tt)
					{
						p=max(p,f[i].c);
						js[3]++;
					}
					if(p!=-1)
					{
						ans+=p;
						if(p==f[i].b&&f[i].c>tt) js[3]--;
						if(p==f[i].c&&f[i].b>tt) js[2]--;
						continue;
					}
				}
				if(f[i].e==2)
				{
					int p=-1;
					if(f[i].a>tt)
					{
						p=f[i].a;
						js[1]++;
					}
					if(f[i].c>tt)
					{
						p=max(p,f[i].c);
						js[3]++;
					}
					if(p!=-1)
					{
						ans+=p;
						if(p==f[i].a&&f[i].c>tt) js[3]--;
						if(p==f[i].c&&f[i].a>tt) js[1]--;
						continue;
					}
				}
				if(f[i].e==3)
				{
					int p=-1;
					if(f[i].a>tt)
					{
						p=f[i].a;
						js[1]++;
					}
					if(f[i].b>tt)
					{
						p=max(p,f[i].b);
						js[2]++;
					}
					if(p!=-1)
					{
						ans+=p;
						if(p==f[i].a&&f[i].b>tt) js[2]--;
						if(p==f[i].b&&f[i].a>tt) js[1]--;
						continue;
					}
				}
				ans+=f[i].t-ty[f[i].e][l[f[i].e]];
				l[f[i].e]++;
				sort(ty[f[i].e]+1,ty[f[i].e]+1+r[f[i].e]);
			}
			else
			{
				ans+=f[i].t;
				js[f[i].e]++;
				r[f[i].e]++;
				ty[f[i].e][r[f[i].e]]=f[i].t;
				sort(ty[f[i].e]+1,ty[f[i].e]+1+r[f[i].e]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
