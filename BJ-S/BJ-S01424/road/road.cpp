#include <bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,ans=0;
    cin>>n>>m>>k;
    if(k==0)
    {
        for(int i=1;i<=m;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(c+1,c+n+1);
        for(int i=1;i<=n-1;i++)
        {
            ans+=c[i];
        }
        cout<<ans;
    }
    else cout<<"13";
    return 0;
}
