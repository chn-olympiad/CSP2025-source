#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<cstdio>
#include<utility>
#include<vector>
using namespace std;
struct node
{
	int lx,ly,lc;
}tr[1000100];
int fa[1001100];
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=x;
}
void make(int lx,int ly)
{
	lx=find(lx);
	ly=find(ly);
	if(lx>ly)swap(lx,ly);
	fa[ly]=lx;
}
int cmp(node lx,node ly)
{
	return lx.lc<ly.lc;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>tr[i].lx>>tr[i].ly>>tr[i].lc;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(tr+1,tr+m+1,cmp);
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		if(find(tr[i].lx)!=find(tr[i].ly))
		{
			make(tr[i].lx,tr[i].ly);
			sum+=tr[i].lc;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

