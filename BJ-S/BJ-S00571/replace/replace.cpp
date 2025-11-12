#include<bits/stdc++.h>
#define int long long
using namespace std;
const int bs = 37 , mod = 105110107;
int n , q , l , r , bsm[5000005] , hsh , hsh2 , fn , pl , cnt , hal[5000005] , hal2[5000005] , ans;
struct p
{
    int l , r , hsh , hsh2 , ln;
};
unordered_map<int , int> mp;
vector<p> d[200005];
string s1 , s2;
inline int calh(int l , int r)
{
    if(l == 0)
    {
        return hal[r];
    }
    return (hal[r] - hal[l - 1] * bsm[r - l + 1] % mod + mod) % mod;
}
inline int calh2(int l , int r)
{
    if(l == 0)
    {
        return hal2[r];
    }
    return (hal2[r] - hal2[l - 1] * bsm[r - l + 1] % mod + mod) % mod;
}
signed main()
{
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bsm[0] = 1;
    for(int i = 1 ; i <= 5000002 ; i++)
    {
        bsm[i] = bsm[i - 1] * bs % mod;
    }
    cin >> n >> q;
    while(n--)
    {
        cin >> s1 >> s2;
        l = -1;
        for(int i = 0 ; i < s1.size() ; i++)
        {
            if(s1[i] != s2[i])
            {
                if(l == -1)
                {
                    l = i;
                }
                r = i;
            }
        }
        if(l == -1)
        {
            continue;
        }
        hsh = hsh2 = 0;
        for(int i = l ; i <= r ; i++)
        {
            hsh = (hsh * bs + s1[i] - 'a' + 1) % mod;
            hsh2 = (hsh2 * bs + s2[i] - 'a' + 1) % mod;
        }
        fn = hsh * 1000000000ll + hsh2;
        if(!mp[fn])
        {
            cnt++;
            mp[fn] = cnt;
        }
        pl = mp[fn];
        hsh = hsh2 = 0;
        for(int i = 0 ; i < s1.size() ; i++)
        {
            hsh = (hsh * bs + s1[i] - 'a' + 1) % mod;
            hsh2 = (hsh2 * bs + s2[i] - 'a' + 1) % mod;
        }
        d[pl].push_back({l , r , hsh , hsh2 , s1.size()});
    }
    while(q--)
    {
        cin >> s1 >> s2;
        if(s1.size() != s2.size())
        {
            cout << "0\n";
            continue;
        }
        l = -1;
        for(int i = 0 ; i < s1.size() ; i++)
        {
            if(s1[i] != s2[i])
            {
                if(l == -1)
                {
                    l = i;
                }
                r = i;
            }
        }
        if(l == -1)
        {
            cout << "0\n";
            continue;
        }
        hsh = hsh2 = 0;
        for(int i = l ; i <= r ; i++)
        {
            hsh = (hsh * bs + s1[i] - 'a' + 1) % mod;
            hsh2 = (hsh2 * bs + s2[i] - 'a' + 1) % mod;
        }
        fn = hsh * 1000000000ll + hsh2;
        if(mp.find(fn) == mp.end())
        {
            cout << "0\n";
            continue;
        }
        pl = mp[fn];
        hal[0] = s1[0] - 'a' + 1;
        hal2[0] = s2[0] - 'a' + 1;
        for(int i = 1 ; i < s1.size() ; i++)
        {
            hal[i] = (hal[i - 1] * bs + s1[i] - 'a' + 1) % mod;
            hal2[i] = (hal2[i - 1] * bs + s2[i] - 'a' + 1) % mod;
        }
        ans = 0;
        for(int i = 0 ; i < d[pl].size() ; i++)
        {
            if(calh(l - d[pl][i].l , l - d[pl][i].l + d[pl][i].ln - 1) == d[pl][i].hsh)
            {
                if(calh2(l - d[pl][i].l , l - d[pl][i].l + d[pl][i].ln - 1) == d[pl][i].hsh2)
                {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
T3 replace (50pts+)

思考 18

代码 11 发现做法假了

思考 13

代码 18 发现做法假了*2

思考 19 O(sum ans)

代码 51

对拍 5 Wa

代码 20

对拍 6
*/