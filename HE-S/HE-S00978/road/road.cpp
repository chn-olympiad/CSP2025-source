#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,u[100100],v[100100],w[100100],c[11][10010],minn=INT_MAX,t;
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i][1];
		if(minn>c[i][1])
		{
			minn=c[i][1];
			t=i;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j+1];
		}
	}
	sort(w+1,w+1+n);
	sort(c[t]+2,c[t]+2+n);
	cout<<w[1]+w[2]+c[t][1]+c[t][2]+c[t][3];
	return 0;
}
