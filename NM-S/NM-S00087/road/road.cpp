#include<bits/stdc++.h>
using namespace std;
int n,m,k,xz[20],bc[100100];
long long ans=0;
struct node{
	int u,v,w;
}q[100100];
int find(int iop)
{
	if(bc[iop]==iop || bc[iop]==0)return iop;
	return bc[iop]=find(bc[iop]);
}
int hb(int q,int w)
{
	int a,b;
	a=find(q);b=find(w);
	bc[w]=bc[q]=a;
	return 0;
}
int main()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	    scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);
	for(int i=1;i<=n;i++)
	{
		int a=1;
		for(int j=1;j<=m;j++)
			if(q[j].w<q[a].w && find(q[j].u)!=find(q[j].v))
				a=j;
		hb(q[a].u,q[a].v);
		ans+=q[a].w;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
/*
4 4 0
1 2 1
1 3 1
2 3 4
1 5 1
1 4 3
4 5 2
*/
