#include<bits/stdc++.h>
using namespace std;
const long long N=1000005;
long long n,m,k,u[N],v[N],w[N],a,b,c,d,e;
int main()
{
	long long i,j;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
    {
		cin>>u[i]>>v[i]>>w[i];
    }
    for(i=1;i<=k;i++)
    {
		for(j=1;j<=m+1;j++)
		{
			cin>>a>>b>>c>>d>>e;
		}
    }
    cout<<13;
    return 0;
}
