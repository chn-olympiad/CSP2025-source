#include<bits/stdc++.h>
using namespace std;
int t,n,m,b[100005],k,ans;
struct ll{
	int u,v,w;
}a[100005];
bool cmp(ll x,ll y)
{
	return x.w>y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
		ans+=a[i].w;
	cout<<ans;
	return 0;
} 
