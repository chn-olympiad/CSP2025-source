#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 998244353;
const int N = 5e3;
struct num{int now , r;};
vector <num> a;
long long ans;
void DFS(int d , vector <num>& v)
{
    if (d == 3) return;
    int n = v.size();
    vector <num> b;
    for (int i = 0 ; i < n - 1 ; ++i)
    {
        for (int j = i + 1 ; j < n ; ++j)
        {
            int sum = v[i].now + v[j].now;
            b.push_back(num{sum ,v[j].r});
            if (d >= 2 && sum > a[v[j].r].now)
                ans = (ans + 1) % MOD;
        }
    }
    DFS(d + 1 , b);
}
int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        int t; cin >> t;
        a.push_back(num{t , i});
        cnt += (t == 1);
    }
    sort(a.begin(), a.end() , [](num x , num y){return x.now < y.now;});
    if (n <= 3)
    {
        if (n == 3)
            cout << (a[0].now + a[1].now + a[2].now > a[2].now * 2) << endl;
        else cout << 0 << endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if (cnt == n)
    {
        long long cur = 1;
        for (int i = n ; i >= 4 ; --i)
        {
            cur *= i;
            ans = (ans + cur) % MOD;
        }
        cout << ans % MOD << endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    DFS(1 , a);
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
