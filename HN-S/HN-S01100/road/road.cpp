#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,u[N],v[N],w[N],a[N][N],c[N];
bool cmp(int x,int y)
{
	return x<y;
}
int main(){
	freopen("road.in","r",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>c[j]>>a[j][i];
			
		}
	}
	sort(w+1,w+1+n,cmp);
	for(int i=1;i<n;i++)
	{
		sum+=w[i];
	}
	cout<<sum;
	freopen("road.out","w",stdout);
	return 0;
}
