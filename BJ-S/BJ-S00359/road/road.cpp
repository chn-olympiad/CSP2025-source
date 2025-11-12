#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int c[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    long long cnt=0;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        cnt+=c[i];
    }
    cout<<cnt;
    return 0;
}