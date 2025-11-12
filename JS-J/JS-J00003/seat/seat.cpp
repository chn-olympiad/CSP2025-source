//CSP-J T2 seat
#include <bits/stdc++.h>

#define MAX_N 150
#define MOD 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m;
int a[MAX_N];

bool Cmp( const int &a, const int &b )
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int i;
    int r, c;

    cin>>n>>m;

    for(i=1;i<=n*m;++i)
    {
        cin>>a[i];
    }

    int score = a[1];

    sort(a+1, a+1+n*m, Cmp);

    int cnt = 1;
    bool flag = false;

    for(c=1;c<=m;++c)
    {
        if(c%2!=0)
        {
            for(r=1;r<=n;++r)
            {
                if(a[cnt] == score)
                {
                    flag = true;
                    break;
                }
                ++cnt;
            }
        }
        else
        {
            for(r=n;r>=1;--r)
            {
                if(a[cnt] == score)
                {
                    flag = true;
                    break;
                }
                ++cnt;
            }
        }
        if(flag == true)
            break;
    }

    cout<<c<<' '<<r<<'\n';

    return 0;
}