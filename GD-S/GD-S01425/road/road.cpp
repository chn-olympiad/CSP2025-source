#include<bits/stdc++.h>
using namespace std;
int n,m,k,top,he[1000005],f[10005],ans,x,y,z;
struct xx
{
	int to,ne,nu,st;
}a[2000006];
void ji(int x,int y,int z)
{
	a[++top]={y,he[x],z,x};
	he[x]=top;
}
bool cmp(xx x,xx y)
{
	return x.nu<y.nu;
}
int fi(int x)
{
	if(f[x]!=x)f[x]=fi(f[x]);
	return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		ji(x,y,z);
		ji(y,x,z);
	}
	sort(a+1,a+m*2+1,cmp);
	for(int i=1;i<=m*2;i++)
	{
		if(fi(a[i].st)==fi(a[i].to))continue;
		f[fi(a[i].st)]=fi(a[i].to);
		ans+=a[i].nu;
	}
	cout<<ans;
}

