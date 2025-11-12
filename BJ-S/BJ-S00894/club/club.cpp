#include<bits/stdc++.h>
using namespace std;
const int N = int(1e5) + 10;
int a[N], b[N], val[N], cnt[5];
void Solve()
{
    int n;
    cin >> n;
    long long res = 0;
    cnt[1] = cnt[2] =  cnt[3] = 0;
    for(int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = max({x, y, z});
        b[i] = x + y + z - max({x, y, z}) - min({x, y, z});
        res += a[i];
        if(x == a[i])
        {
            val[i] = 1;
            cnt[1]++;
        }
        else if(y == a[i])
        {
            val[i] = 2;
            cnt[2]++;
        }
        else
        {
            val[i] = 3;
            cnt[3]++;
        }
    }
    for(int j = 1; j <= 3; j++)
    {
        if(cnt[j] > (n >> 1))
        {
            vector<int> vec;
            for(int i = 1; i <= n; i++)
                if(val[i] == j) vec.push_back(b[i] - a[i]);
            sort(vec.begin(), vec.end(), greater<int>());
            for(int i = 0; i < cnt[j] - (n >> 1); i++) res += vec[i];
            break;
        }
    }
    cout << res << '\n';
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) Solve();
    return 0;
}