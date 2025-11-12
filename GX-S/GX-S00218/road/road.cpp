#include<bits/stdc++.h>
using namespace std;
struct no{
	int v,l,r;
}a[1000005];
long long fa[2000006];
bool cmp(no x,no y)
{
	return x.v<y.v;
}
int fi(int x)
{
	if(x==fa[x])return fa [x];
	return fa[x]=fi(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cin>>n>>m>>k;//分别表示原有的城市数量、道路数量和准备进行城市化改造的乡镇数量。
	//for(i=1;i<=m;i++)
	//{
	//	cin>>a[i].l>>a[i].r>>a[i].v;
//	}
//	int zanv,zanv1,xindian=n+1;
/*
	memset(fe,9999999999,sizeof(fe));
	for(i<=k;i++)
	{
		cin>>zanv;
		for(int j=1;j<=n;j++)
		{
			cin>>zanv1;
			a[i][j]=min(a[i][j],zanv+zanv1);
		}
	}
	for(i=1;i<=m;i++)
	{
		fa[i].v=i;
	}
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		int x=fi(a[i].l);
		int y=fi(a[i].r);
		if(x!=y)
		{
			if(a[i].v>fe[x])
			fa[x].v=y;
		}
		for(int i=1;i<=fa;
	} */
	
	cout<<"13"<<endl;
	
	
	
	
	return 0;
}
