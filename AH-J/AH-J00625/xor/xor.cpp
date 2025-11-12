#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N];
int dp[N];
vector <pair<int, int> > pq;
int cmp(pair <int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    freopen("xor.in", "r", stdin);
  freopen("xor.out", "w",stdout);
    cin >>n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] ^ a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            if ((dp[j] ^ dp[i - 1] )== k){
                pq.push_back(make_pair(i, j));
            }
        }
    }
    sort(pq.begin(), pq.end(), cmp);
    int sum = 1;
    int R = pq[0].second;
    for (int i = 1; i < pq.size(); ++i)
    {
       // cout << pq[i].first << " " << R <<"\n";
        if (R < pq[i].first )
        {
            R = pq[i].second;
            sum++;
        }
    }
    cout << sum;
    return 0;
}
