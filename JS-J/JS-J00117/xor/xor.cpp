#include <bits/stdc++.h>
using namespace std;
long long n , k , a[500500] , cnt , idx , last , ans;
vector<pair<int , int>> v;
int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    for(int i=1 ; i<=n ; i++)
    {
        cnt = 0;
        for(int j=i ; j<=n ; j++)
        {
            cnt ^= a[j];
            if(cnt == k)
            {
                v.push_back(make_pair(i , j));
                break;
            }
        }
    }
    for(long long i=0 ; i<v.size() ; i++)
    {
        idx = 1;
        last = v[i].second;
        for(long long j=i+1 ; j<v.size() ; j++)
        {
            if(v[j].first <= last) continue;
            else
            {
                last = v[j].second;
                idx ++;
            }
        }
        ans = max(ans , idx);
    }
    cout << ans;
    return 0;
}
