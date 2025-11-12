#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200000][4];
int b[4];
int c[200000];
int n,zs=-1,gs=0,cs=0;
void dfs(int x)
{
    if(x>n)
    {
        zs=max(zs,gs);
        cs++;
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(b[i]==n/2)
        {
            continue;
        }
        gs+=a[x][i];
        b[i]++;
        dfs(x+1);
        gs-=a[x][i];
        b[i]--;
    }
    return;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int tj=0;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            if(a[j][2]!=0||a[j][3]!=0)
            {
                tj=1;
            }
        }
        if(tj==0)
        {
            int xxyy=0;
            for(int j=1;j<=n;j++)
            {
                c[j]=a[j][1];
            }
            sort(c+1,c+n+1);
            for(int i=n;i>n/2;i--)
            {
                xxyy+=c[i];
            }
            cout<<xxyy<<"\n";
        }
        else{
            dfs(1);
            cout<<zs<<"\n";
            zs=-1;
        }
    }

    return 0;
}
