//J00694 at here
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int Mod = 998244353;

int n,a[10086];
int cnt;

int poww(int x,int y)
{
    int sum = 1;
    for(int i = 1;i <= y;i++)
    {
        sum *= x;
        sum %= Mod;
    }
    return sum;
}

void dfs(int now,int sum,int ge,int biggest)
{
//for(int i = 1;i <= now;i++) cout << "  ";
//cout << now << " " << sum << " " << ge << " " << biggest << endl;
    if(now == n+1)
    {
        if(ge < 3) return;
        if(sum > 2 * biggest) cnt++;
        cnt %= Mod;
//for(int i = 1;i <= now+1;i++) cout << "  ";
//cout << "+1" << endl;
        return;
    }
    if(ge >= 3 && sum > 2 * biggest)
    {
        cnt += poww(2,n-now+1);
//for(int i = 1;i <= now+1;i++) cout << "  ";
//cout << "+" << poww(2,n-now+1) << endl;
        return;
    }

    dfs(now+1,sum+a[now],ge+1,(biggest == -1 ? a[now] : biggest));
    dfs(now+1,sum,ge,biggest);
}

bool cmp(const int &x,const int &y) {return x > y;}

void case1()
{
    sort(a+1,a+n+1,cmp);
    dfs(1,0,0,-1);
    cout << cnt;
}

void case2()
{
    int ans = poww(2,n);
    int no = n + (n * (n-1) % Mod) / 2;
    cout << ans - no;
}

signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)cin >>a[i];

    if(n <= 20)
    {
        case1();
        return 0;
    }

    int maxn = 0;
    for(int i = 1;i <= n;i++) maxn = max(maxn,a[i]);
    if(maxn <= 1)
    {
        case2();
        return 0;
    }

    case1();
    return 0;
}
