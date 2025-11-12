#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000009;
int t,n,a[N][5],ansh,hh[5];
void zz(int x,int y)
{
    if(x==n+1)
    {
        ansh=max(ansh,y);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(hh[i]>=n/2)
        {
            continue;
        }
        hh[i]++;
        zz(x+1,y+a[x][i]);
        hh[i]--;
    }
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(hh,0,sizeof(hh));
        ansh=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        zz(1,0);
        cout<<ansh<<endl;
    }
    return 0;
}
