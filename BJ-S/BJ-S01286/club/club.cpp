#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N],b[N],c[N];
int ans=0;
int res[10],t[N][10],sum[10];
void dfs(int x)
{
    if(x==n+1)
    {
        ans=max(ans,sum[1]+sum[2]+sum[3]);
        return ;
    }
    t[x][1]=a[x],t[x][2]=b[x],t[x][3]=c[x];
    for(int i=1;i<=3;i++)
    {

        if(res[i]<n/2)
        {
            sum[i]+=t[x][i];
            res[i]++;
            dfs(x+1);
            res[i]--;
            sum[i]-=t[x][i];
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i]>>b[i]>>c[i];
        if(n>15)
        {
            sort(a+1,a+n+1);
            for(int i=n;i>=n/2;i--)
            {
                ans+=a[i];
            }
            cout<<ans<<"\n";
            continue;
        }
        dfs(1);
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}
