//SZ-S00400 遵义市南白中学 袁双全 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int u;
	int v;
	long long w;
	int id;
}lin[1000005];
long long cou[20][10005];
long long ans=9999999999999999;
bool num[20];
int cnt;
int cnt2;
int f[10050];
int v[20];
int find(int x)
{
	if(f[x]==x) return x;
	else 
	{
		x=f[x];
		return find(x);
	}
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
void spfa()
{
	long long an=0;
	for(int i=1;i<=n+k;i++)
	f[i]=i;
	int li=0;
	for(int i=1;i<=cnt;i++)
	{
		if(lin[i].id==0||num[lin[i].id]==1)
		{
			f[lin[i].u]=find(lin[i].u);
			f[lin[i].v]=find(lin[i].v);
//			cout<<lin[i].u<<" "<<lin[i].v<<endl;
			if(f[lin[i].u]!=f[lin[i].v])
			{
				f[f[lin[i].u]]=f[lin[i].v];
				li++;
				an+=lin[i].w;
			}
//			for(int j=1;j<=5;j++)
//			cout<<f[j]<<" ";
//			cout<<endl;
			if(li==n+cnt2-1)
			break;
		}
	}
	for(int i=1;i<=k;i++)
	if(num[i]) an+=v[i];
//	cout<<an<<endl;
	ans=min(ans,an);
}
void find(int x,int f)
{
	if(f==0)
	{
		long long p=0;
		for(int i=1;i<=k;i++)
		if(num[i]) p+=v[i];
		if(p<ans)
		spfa();
		return; 
	}
	for(int i=x+1;i<=k-f+1;i++)
	{
		num[i]=1;
		cnt2++;
		find(i,f-1);
		num[i]=0;
		cnt2--;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>lin[i].u>>lin[i].v>>lin[i].w;
		lin[i].id=0;
	}
	cnt=m;
	for(int i=1;i<=k;i++)
	{
		cin>>v[i];
		for(int j=1;j<=n;j++)
		{
			cin>>cou[i][j];
			lin[++cnt].w=cou[i][j];
			lin[cnt].u=n+i;
			lin[cnt].v=j;
			lin[cnt].id=i;
		}
	}
	sort(lin+1,lin+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++)
//	cout<<lin[i].w<<" ";
//	cout<<endl;
	for(int i=0;i<=k;i++)
	{
		find(0,i);
	}
	cout<<ans;
	return 0;
} 
