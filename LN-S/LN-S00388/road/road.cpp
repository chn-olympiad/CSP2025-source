#include<bits/stdc++.h>
using namespace std;
int f[11000];
struct lu
{
	int from;
	int to;
	long long chang;
}l[1000100];
int find(int x11)
{
	if(x11==f[x11])
	return x11;
	f[x11]=find(f[x11]);
	return f[x11];
}
int panduan(int x22,int y22)
{
	if(find(x22)==find(y22))
	return 1;
	return 0;
}
void hebin(int x33,int y33)
{
	f[f[x33]]=f[y33];
}
bool cmp(lu xx,lu yy)
{
	return xx.chang<=yy.chang;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//whw
	int n,m,kk,k=1;
	scanf("%d%d%d",&n,&m,&kk);
	for(int i=1;i<=m;i++)
	{
		int v,u;
		long long o;
	    scanf("%d%d%lld",&v,&u,&o);
	    l[k].from=v;
	    l[k].to=u;
	    l[k].chang=o;
	    k++;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	//	cout<<f[i];
	}
	sort(l+1,l+1+m,cmp);
	int cus=0;
	long long s=0;
	for(int i=1;i<=m;i++)
	{
		if(cus==n-1)break;
		int p=l[i].from,q=l[i].to;
		//cout<<p<<" "<<q<<endl;
		if(panduan(p,q)==1)
		{
			//cout<<1;
			continue;
		}
		//cout<<1;
		hebin(p,q);
		cus++;
		s=s+l[i].chang;
	}
	//for(int i=1;i<=n;i++)cout<<f[i]<<endl;
	cout<<s;
	return 0;
	//4 4 0 2 3 1 2 1 1 1 3 1 2 4 1
}
