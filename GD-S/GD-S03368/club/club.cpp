#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int t,n,a[MAXN][4],m_mem,ans=0,b[MAXN][4],xu[MAXN][4],vis[4],my;

struct js
{
	int v,w;
};

bool cmp(js x,js y)
{
	return x.v<y.v;
}

int tc(int x)
{
	int r,l,cnt=0;
	if(x==1) r=2,l=3;
	if(x==2) r=1,l=3;
	if(x==3) r=1,l=2;
	js pop1[vis[x]+2],pop2[vis[x]+2];
	int ss=vis[x]; 
	for(int i=1;i<=vis[x];i++)
	{
		pop1[i].w=i;
		pop2[i].w=i;
		pop1[i].v=b[xu[i][x]][r];
		pop2[i].v=b[xu[i][x]][l];
	}
	sort(pop1+1,pop1+vis[x]+1,cmp);
	sort(pop2+1,pop2+vis[x]+1,cmp);
	for(int i=1,j=1;ss+2-i-j>m_mem;)
	{
		vis[x]--;
		if(pop1[i].v<pop2[j].v)
		{
			
			vis[r]++;
			xu[vis[r]][r]=xu[pop1[i].w][x];
			cnt+=pop1[i].v;
			i++;
		}
		else
		{
			vis[l]++;
			xu[vis[l]][l]=xu[pop2[j].w][x];
			cnt+=pop2[j].v;
			j++;
		}
	}
	my=x;
	return cnt;
}

int qc(int x,int y)
{
	int cnt=0,ss=vis[x];
	int l;
	if(y!=1 && x!=1) l=1;
	else if(y!=2 && x!=2) l=2;
	else l=3;
	js pop[vis[x]];
	for(int i=1;i<=vis[x];i++)
	{
		pop[i].w=i;
		pop[i].v=b[xu[i][x]][l]-b[xu[i][x]][x];
	}
	sort(pop+1,pop+vis[x]+1,cmp);
	for(int i=1;i+m_mem<ss+1;i++)
	{
		vis[x]--;
		cnt+=pop[i].v;
	}
	return cnt;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m_mem=n/2;
		for(int i=1,max_in;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			max_in=max(a[i][1],max(a[i][2],a[i][3]));
			b[i][1]=max_in-a[i][1];
			b[i][2]=max_in-a[i][2];
			b[i][3]=max_in-a[i][3];
			ans+=max_in;
			if(b[i][1]==0) xu[++vis[1]][1]=i;
			else if(b[i][2]==0) xu[++vis[2]][2]=i;
			else xu[++vis[3]][3]=i;
		}
		for(int i=1;i<=3;i++)
		{
			if(vis[i]>m_mem)
			{
				ans-=tc(i);
				break;
			}
		}	
		for(int i=1;i<=3;i++)
		{
			if(vis[i]>m_mem)
			{
				ans-=qc(i,my);
				break;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=3;i++) vis[i]=0;
		my=0,ans=0;
	}
	return 0;
}
