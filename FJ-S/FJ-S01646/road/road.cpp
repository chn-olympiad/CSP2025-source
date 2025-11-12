#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
using namespace std;
int n,m,k;
int c[13],a[12][10004];
struct cc{
	int u,v,w;
}b[1000006];
bool cmp(cc q,cc w){
	return q.w<w.w;
}
int main()
{
	IOS
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>b[i].u>>b[i].v>>b[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(b+1,b+m+1,cmp);
	ll c=0;
	for(int i=1;i<=m;i++)
		c+=b[i].w;
	cout<<c;
}
