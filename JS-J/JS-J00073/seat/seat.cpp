#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int ans;
vector<int> a;
bool cmp(int x, int y)
{
    return x > y;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for (int i = 1; i <= n*m; i ++)
    {
        int x;scanf("%lld",&x);
        if(i==1) ans = x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(),cmp);
    int x;
    for (int i = 0; i < a.size(); i ++)
    {
        if(a[i] == ans)
        {
            x = i+1;
            break;
        }
    }
    //c
    int c;
    if(x%n==0) c = x/n;
    else c = x/n + 1;
    //r
    int r;
    if(c%2 == 1)
    {
        if(x%n == 0)
        {
            r = n;
        }
        else r = x % n;
    }
    else
    {
        if(x%n==0)r = 1;
        else
        {
            r = n - x % n + 1;
        }
    }
    printf("%lld %lld",c,r);
    return 0;
}
