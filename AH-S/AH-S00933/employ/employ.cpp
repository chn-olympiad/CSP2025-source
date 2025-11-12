#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e6+5;
const ll mod = 998244353;
ll n,m;
string mode;
int a[maxn],b[maxn];
bool special_task_A = 1;
int count_of_not_zero_human = 0;
void init()
{
    cin >> n >> m;
    cin >> mode;
    for(auto c : mode)
    {
        if(c == '0')
        {
            special_task_A = 0;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i]) {
            count_of_not_zero_human++;
            // cout << a[i] << " " << count_of_not_zero_human << endl;
        }
        b[i] = i;
    }
    // cout << count_of_not_zero_human << endl;
}
void work()
{
    if(0){
    if(special_task_A)
    {   
        ll ans = 1;
        ll sum_p=0;
        for(int i = 1;i <= n;i++)
        {
            if(!a[i]){
                sum_p++;
                continue;
            }
            if(a[i] <= sum_p)
            {
                sum_p ++;
                continue;
            }
        }
        int k = n - sum_p;
        for(int i = 1;i <= k;i++)
        {
            ans *= i;
            ans %= mod;
        }
        cout << ans % mod << endl;
        return ;
    }}
    ll ans = 0;
    ll sum_p = 0,cnt = 0;
    do{
        sum_p = cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[b[i]] <= sum_p)
            {
                sum_p++;
                continue;
            }
            if(mode[i-1] == '0')
            {
                sum_p++;
                continue;
            }
            cnt ++;
            cnt %=mod;
        }
        if(cnt >= m)
            ans++;
        ans %= mod;
    } while(next_permutation(b+1,b+1+n));
    cout << ans<< endl;
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    work();
    return 0;
}