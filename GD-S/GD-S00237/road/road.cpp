#include<bits/stdc++.h>
using namespace std;
const int N=10001;

int mmap[N][N];
int main()
{
	int n,m,k,a,b,v,ans=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(mmap,0,(n+1)*(n+1));
	while(m--)
	{
		cin>>a>>b>>v;
		mmap[a][b]=v;
		mmap[b][a]=v;
		ans+=v;
	}
	while(k--) cin>>a>>a>>a>>a>>a;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<mmap[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<ans<<endl;
	return 0;
}
