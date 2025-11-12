//CSP-J T4 polygon
#include <bits/stdc++.h>

#define MAX_N 5050
#define MOD 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
int a[MAX_N];
ull ans;
//int num[MAX_N], c;

void DFS( int cnt, int id, int sum, int m )
{
    if(id == n+1)
    {
        if(cnt <= 3 || sum <= 2*m)
        {
            return ;
        }
        else 
        {
            /*
            int j;
            for(j=1;j<=c;++j)
            {
                cout<<num[j]<<' ';
            }
            cout<<'\n';
            */
            ans = (ans+1)%MOD;
            return ;
        }
    }

    int i = id+1;
    ull ret = 0;

    DFS(cnt, i, sum, m);
    
    if(a[i] != 0)
    {
        //num[++c] = a[i];
        DFS(cnt+1, i, sum+a[i], max(m, a[i]));
        //--c;
    }

    return ;
}

int one;//15~20 max(a[i])=1 ke yi pian fen

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int i;

    cin>>n;

    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i] == 1)
            one++;
    }

    if(n < 3)
    {
        cout<<0<<'\n';
        return 0;
    }
    if(one == n)
    {
        int j;
        for(i=4;i<=n;++i)
        {
            ull t1 = 1, t2 = 1;

            for(j=n;j>n-i;--j)
                t1 = (t1*j)%MOD;
            for(j=1;j<=i;++j)
                t2 = (t2*j)%MOD;
            ans = (ans+((t1/t2)%MOD))%MOD;
        }
    }
    else
        DFS(0, 0, 0, 0);

    cout<<ans%MOD<<'\n';

    return 0;
}
