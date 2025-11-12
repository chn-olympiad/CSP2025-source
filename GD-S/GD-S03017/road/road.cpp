#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int u,v,w,use;
}a[50000001];
struct town
{
	int c,x[10001];
}zhi[11];
bool cmpp(node a,node b)
{
	if(a.w!=b.w)return a.w<b.w;
	if (a.u!=b.u)return a.u<b.u;
	return a.v<b.v;
}
map<int,int>lian;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
		scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
	for (int i=1;i<=k;i++)
		{
		cin>>zhi[i].c;
		for (int j=1;j<=n;j++)
			scanf("%d",&zhi[i].x[j]);
		for (int j=1;j<=n;j++)
			{
			for (int k=1;k<=n;k++)
				{
				if (j==k)continue;
				m++;
				a[m].u=j;
				a[m].v=k;
				a[m].w=zhi[i].c+zhi[i].x[j]+zhi[i].x[k];
				if (m>50000000)break;
				}
			if (m>50000000)break;
			}
		}
	int sum=0;
	sort(a+1,a+1+m,cmpp);
	for (int i=1;i<=m;i++)
		{
		if (lian[a[i].u]==0||lian[a[i].v]==0)
			lian[a[i].u]++,lian[a[i].v]++,sum+=a[i].w,a[i].use=1;
		if (a[i].u==a[i-1].u&&a[i].v==a[i-1].v)a[i].use=1;
		}
	int again=0;
	for (int i=1;i<=m;i++)
		{
		if (lian[a[i].u]>1||lian[a[i].v]>1)
			{
			again=1;
			break;
			}
		}
	if (again==1)cout<<sum;
	else
		{
		for (int i=1;i<=n;i++)
			{
			if (a[i].use==0)
				{
				sum+=a[i].w;
				break;
				}
			/*else
				cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<endl;*/
			}
		cout<<sum;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

