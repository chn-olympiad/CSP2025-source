//CSP-J T3 xor
#include <bits/stdc++.h>

#define MAX_N 500050
#define MOD 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, k;
int a[MAX_N];
ull sum[MAX_N];
ull ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int i, j;

    cin>>n>>k;

    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        sum[i] = sum[i-1]^a[i];
    }

    for(i=1;i<=n;++i)
    {
        for(j=i+1;j<=n;++j)
        {
            if(sum[j]^sum[i-1] == k)
            {
                ++ans;
                break;
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}

//dian nao you shi bao cun bu liao you shi mo ming qi miao chong qi, hai de wo quan dou xie le liang bian, ying jian jing shen zhuang tai liang hao