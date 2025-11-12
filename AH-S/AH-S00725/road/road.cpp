#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,u[100000],v[100000],w[100000],sum=0,a;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++)
		{
		cin>>a;
		if(j==1)
			sum+=a;
		}
    cout<<sum;
    return 0;
}
