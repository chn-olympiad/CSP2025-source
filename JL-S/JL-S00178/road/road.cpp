#include<bits/stdc++.h>
using namespace std;
long long p[10005][10005],z[10005][100005];
int main()
{
	long long sum=0,ssum=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        p[a][b]=c;
        p[b][a]=c;
    }
    for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=m;j++)
		{
			sum=sum+p[i][j];
			ssum++;
		}
	}
	cout<<ssum<<endl;
    return 0;
}
