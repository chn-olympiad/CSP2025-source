#include <bits/stdc++.h>
using namespace std;
int t,n,a[100001][5],sum[1000001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int k=1;k<=n;k++)
        {
			for(int j=1;j<=3;j++)
				cin>>a[k][j];
		    sum[i]+=max(a[k][1],max(a[k][2],a[k][3]));	
		}
	}
    for(int i=1;i<=t;i++)
        cout<<sum[i]<<endl;
    return 0;
}
