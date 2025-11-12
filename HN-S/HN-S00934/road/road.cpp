#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool vi[20];
int vi_b[20];
const int N=1e4+25;
bool b[N+25];
int ma;
struct g
{
	int t;
	vector<int> to;
	vector<int> si;
}ed[N];
void f(int x,int w,int yd)
{
	if(b[x]) return;
	if(yd==n) ma=max(ma,w);
	b[x]=1;
	for(int j=0;j <ed[x].t;j++)
		{
			f(ed[x].to[j],w+ed[x].si[j],yd+1);
		}
	b[x]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		ed[a].t++;
		ed[a].to.push_back(b);
		ed[a].si.push_back(c);
		ed[b].t++;
		ed[b].to.push_back(a);
		ed[b].si.push_back(c);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&vi_b[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a);
			ed[n+1].t++;
			ed[n+i].to.push_back(j);
			ed[n+i].si.push_back(a);
			ed[j].t++;
			ed[j].to.push_back(n+i);
			ed[j].si.push_back(a);
		}
	}
	cout<<ma;
	return 0;
}//goodbye-oi
