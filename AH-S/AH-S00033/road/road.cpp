#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
}ro[2000005];
int c[2000005],xiang[2000005],can[2000005],used[2000005];
int cmp(road a,road b)
{
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
		cin>>ro[i].u>>ro[i].v>>ro[i].w;
	int cnt=m,nn=n;
	for (int i=1;i<=k;i++)
	{
		cin>>xiang[i];
		nn++;
		for (int j=1;j<=n;j++)
		{
			cin>>ro[++cnt].w;
			ro[cnt].w+=xiang[i];
			ro[cnt].u=nn;
			ro[cnt].v=j;
		}
	}
	sort(ro+1,ro+cnt+1,cmp);
	long long s=0;
	for (int i=1;i<=cnt;i++)
	{
		if (can[ro[i].u] && can[ro[i].v]) continue;
		can[ro[i].u]=1,can[ro[i].v]=1;
		if (ro[i].u<=n)	
			s+=ro[i].w;
		else 
		{
			s+=ro[i].w-used[ro[i].u-n];
			used[ro[i].u-n]=xiang[ro[i].u-n];
		}
		int f=1;
		for (int j=1;j<=n;j++)
			if (!can[j])
				f=0;
		if (f==1)
			break;
	}
	cout<<s;
	return 0;
}
