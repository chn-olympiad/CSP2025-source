#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ifstream cin("club.in");
ofstream cout("club.out");
const ll NR=205;
ll f[NR>>1][NR>>1],a[NR][5],n,ans,T,mx2,mx3,q[100005];
void init()
{
    memset(f,0,sizeof(f));
    ans=0;
    mx2=0,mx3=0;
}
bool cmp(ll al,ll bw)
{
    return al>bw;
}
void solve()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        mx2=max(mx2,a[i][2]);
        mx3=max(mx3,a[i][3]);
    }
    if(mx2==0&&mx3==0)
    {
        for(ll i=1;i<=n;i++)
            q[n]=a[i][1];
        sort(q+1,q+n+1,cmp);
        for(ll i=1;i<=n/2;i++)
            ans+=q[i];
        cout<<ans<<endl;
        return ;
    }
    for(ll k=1;k<=n;k++)
    {
        for(ll i=min(k,n/2);i>=0;i--)
            for(ll j=min(k-i,n/2);j>=0;j--)
            {
                if(i==0&&j==0)
                    f[i][j]=f[i][j]+a[k][3];
                else if(i==k)
                    f[i][j]=f[i-1][j]+a[k][1];
                else if(j==k)
                    f[i][j]=f[i][j-1]+a[k][2];
                else if(i==0)
                    f[i][j]=max(f[i][j-1]+a[k][2],f[i][j]+a[k][3]);
                else if(j==0)
                    f[i][j]=max(f[i-1][j]+a[k][1],f[i][j]+a[k][3]);
                else if(i+j==k)
                    f[i][j]=max(f[i-1][j]+a[k][1],f[i][j-1]+a[k][2]);
                else
                    f[i][j]=max(f[i-1][j]+a[k][1],max(f[i][j-1]+a[k][2],f[i][j]+a[k][3]));
            }
    }
    for(ll i=0;i<=n/2;i++)
    {
        for(ll j=(n/2-i);j<=n/2;j++)
            ans=max(ans,max(f[i][j],f[j][i]));
    }
    cout<<ans<<endl;
    return ;
}
int main()
{
    cin>>T;
    while(T--)
    {
        init();
        solve();
    }
    return 0;
}
