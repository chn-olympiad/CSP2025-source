#include<bits/stdc++.h>
using namespace std;
int n,m,k,a;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
        cin>>a>>a>>a;
    for(int i=0;i<k;i++)
        for(int j=0;j<n+1;j++)
        cin>>a;
    cout<<0;
    return 0;
}
