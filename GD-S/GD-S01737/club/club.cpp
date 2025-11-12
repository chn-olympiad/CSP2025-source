#include<bits/stdc++.h>
using namespace std;
int t,n,vis[100005],tota,totb,totc,ans;
int ta[100005],tb[100005],tc[100005];
struct str{
	int a,b,c,vis,tmp;
}q[100005];
bool cmpa(int x,int y)
{
	if(q[x].b!=q[y].b) return q[x].b<q[y].b;
	else if(q[x].c!=q[y].c) return q[x].c<q[y].c;
	else return q[x].a>q[y].a;
}
bool cmpb(int x,int y)
{
	if(q[x].c!=q[y].c) return q[x].c<q[y].c;
	else if(q[x].a!=q[y].a) return q[x].a<q[y].a;
	else return q[x].b>q[y].b;
}
bool cmpc(int x,int y)
{
	if(q[x].a!=q[y].a) return q[x].a<q[y].a;
	else if(q[x].b!=q[y].b) return q[x].b<q[y].b;
	else return q[x].c>q[y].c;
}
void fun()
{
	memset(vis,0,sizeof vis);
	memset(ta,0,sizeof ta);
	memset(tb,0,sizeof tb);
	memset(tc,0,sizeof tc);
	tota=totb=totc=n=ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].c);
	for(int i=1;i<=n;i++)
	{
		if(q[i].a>=q[i].b&&q[i].a>=q[i].c) ta[++ta[0]]=i;
		else if(q[i].b>=q[i].c&&q[i].b>=q[i].a) tb[++tb[0]]=i;
		else if(q[i].c>=q[i].a&&q[i].c>=q[i].b) tc[++tc[0]]=i;
	}
	sort(ta+1,ta+1+ta[0],cmpa);
	sort(tb+1,tb+1+tb[0],cmpb);
	sort(tc+1,tc+1+tc[0],cmpc);
	for(int i=1;i<=ta[0];i++)
	{
		if(vis[ta[i]]==1) continue;
		tota++;
		if(tota>n/2) break;
		vis[ta[i]]=1;
		ans+=q[ta[i]].a; 
	}
	for(int i=1;i<=tb[0];i++)
	{
		if(vis[tb[i]]==1) continue;
		totb++;
		if(totb>n/2) break;
		vis[tb[i]]=1;
		ans+=q[tb[i]].b;
	}
	for(int i=1;i<=tc[0];i++)
	{
		if(vis[tc[i]]==1) continue;
		totc++;
		if(totc>n/2) break;
		vis[tc[i]]=1;
		ans+=q[tc[i]].c;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(q[i].a>=q[i].b&&q[i].a>=q[i].c&&tota<n/2) ans+=q[i].a; 
			else if(q[i].b>=q[i].c&&totb<n/2) ans+=q[i].b; 
			else if(totc<n/2) ans+=q[i].c;
		}
	}
	printf("%d",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		fun();
		if(t!=0) printf("\n");
	} 
	return 0;
}

