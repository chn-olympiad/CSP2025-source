#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=110;
int n,m;
int a[N];
int mp[15][15];
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    int len=n*m;
    int cnt=0;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int R=a[1];
    sort(a+1,a+len+1,cmp);
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
            for(int i=1;i<=n;i++) mp[i][j]=a[++cnt];
        else
            for(int i=n;i>=1;i--) mp[i][j]=a[++cnt];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]==R)
            {
                cout<<j<<' '<<i;
                return 0;
            }
    return 0;
}
