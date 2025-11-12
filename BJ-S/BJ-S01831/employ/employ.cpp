#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod=998244353;

int ti[505],nx[505];
int n,m;
int sum=0;
bool vis[505];

void dfs(int step,int shang,int xia)
{
    if (shang+(n-step+1)<m) return;
    if (shang>=m)
    {
        int shu=1;
        for (int i=1;i<=n-step+1;i++)
            shu=shu*i%mod;
        sum=sum+shu;
        return;
    }
    if (step>n) return;
    for (int i=1;i<=n;i++)
        if (!vis[i])
        {
            vis[i]=true;
            if (nx[i]>xia && ti[step]==1) dfs(step+1,shang+1,xia);
            else dfs(step+1,shang,xia+1);
            vis[i]=false;
        }
}

bool cmp(int x,int y)
{
    return x>y;
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    bool tii=true;
    int maxren=0;
    int diyi=2e9;
    int yi=0;
    for (int i=1;i<=n;i++)
    {
        char c;
        cin >> c;
        ti[i]=c-'0';
        tii=tii&ti[i];
        yi=yi+ti[i];
        if (ti[i]==1 && diyi==2e9)
            diyi=i;
    }
    for (int i=1;i<=n;i++)
    {
        cin >> nx[i];
        maxren=max(maxren,nx[i]);
    }
    sort(nx+1,nx+n+1,cmp);
    if (tii)
    {
        //cout << "&&&" << endl;
        int ans=1;
        for (int i=1;i<=n;i++)
            ans=ans*i%mod;
        cout << ans << endl;
        return 0;
    }
    if (maxren<diyi-1 || yi<m)
    {
        cout << 0 << endl;
        return 0;
    }
    if (m==1)
    {
        int sum=1;
        int shu=1;
        while (nx[shu]>=diyi)
            shu++;
        for (int i=1;i<n;i++)
            sum=sum*i%mod;
        sum=sum*(shu-1)%mod;
        cout << sum << endl;
        return 0;
    }
    dfs(1,0,0);
    cout << sum << endl;

    return 0;
}
