#include<bits/stdc++.h>
using namespace std;
int flat[10004],n,m,k,num,ans,now,fa2,fa1,c[11];
struct edge
{
	int u,v,w;
}e[1000001];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int tmp)
{
	if(flat[tmp]==tmp)return tmp;
	flat[tmp]=find(flat[tmp]);
	return flat[tmp];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		ans=0;
		num=0;
		now=1;
		for(int i=1;i<=m;i++)
		{
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		for(int i=1;i<=n;i++)flat[i]=i;
		sort(e+1,e+1+m,cmp);
		while(num<n-1)
		{
			fa1=find(e[now].u);
			fa2=find(e[now].v);
			if(fa1!=fa2)
			{
				ans+=e[now].w;
				num++;
				flat[fa1]=fa2;
			}
			now++;
		}
		cout<<ans<<endl;
	}
	else 
	{
		cout<<0<<endl;
	}
	return 0;
}
