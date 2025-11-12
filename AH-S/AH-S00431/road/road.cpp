#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
const int N=1e5+10;
const int M=1e6+10;
struct Node{
	int x1,y91;
}v[N];
int a[N][M],x[N],y[N],c[N];
bool cmp(Node a,Node b)
{
	return a.x1<b.x1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i]>>v[i].x1;
		v[i].y91=i;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(v+1,v+1+m,cmp);
	for(int i=1;i<=n;i++)
		ans+=y[v[i].y91]-x[v[i].y91];
	cout<<ans<<endl;
	return 0;
}
//0zzc
//BLCQJ,DBCSY,SNOIYCK,BK long long JZZ,SSNOI,SSNCSP,MQSNMJQ!
