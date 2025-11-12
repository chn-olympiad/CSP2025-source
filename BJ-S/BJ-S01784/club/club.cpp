#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,ans,sz[4],sum,idx;
struct node
{
	int id[5],va[5];
}a[N],tmp,v[4][N];
bool cmp(node x,node y)
{
	return x.va[1]>y.va[1];
}
bool cmp2(node x,node y)
{
	return x.va[1]-x.va[2]>y.va[1]-y.va[2];
}
void sol()
{
	cin>>n;
	ans=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].va[1]>>a[i].va[2]>>a[i].va[3];
		a[i].id[1]=1,a[i].id[2]=2,a[i].id[3]=3,a[i].va[4]=-2e9;
		if(a[i].va[1]<a[i].va[2]) swap(a[i].va[1],a[i].va[2]),swap(a[i].id[1],a[i].id[2]);
		if(a[i].va[2]<a[i].va[3]) swap(a[i].va[2],a[i].va[3]),swap(a[i].id[2],a[i].id[3]);
		if(a[i].va[1]<a[i].va[2]) swap(a[i].va[1],a[i].va[2]),swap(a[i].id[1],a[i].id[2]);
		if(a[i].va[2]<a[i].va[3]) swap(a[i].va[2],a[i].va[3]),swap(a[i].id[2],a[i].id[3]);
	}
	sort(a+1,a+n+1,cmp),sz[1]=0,sz[2]=0,sz[3]=0;
	for(int i=1;i<=n;i++)
	{
		v[a[i].id[1]][++sz[a[i].id[1]]]=a[i];
		sum+=a[i].va[1];
	}
	if(sz[1]<=n/2&&sz[2]<=n/2&&sz[3]<=n/2)
	{
		cout<<sum<<'\n';
		return;
	}
	if(sz[1]>n/2) idx=1;
	if(sz[2]>n/2) idx=2;
	if(sz[3]>n/2) idx=3;
	sort(v[idx]+1,v[idx]+sz[idx]+1,cmp2);
	for(int i=1;i<=n/2;i++) ans+=v[idx][i].va[1];
	for(int i=n/2+1;i<=sz[idx];i++) ans+=v[idx][i].va[2];
	for(int i=1;i<=3;i++)
	{
		if(i==idx) continue;
		for(int j=1;j<=sz[i];j++) ans+=v[i][j].va[1];
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) sol();
	return 0;
}
