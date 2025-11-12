#include <bits/stdc++.h>
using namespace std;
const unsigned long long base = 29, mod = (1ull << 61) - 1;

unordered_map<unsigned long long, unordered_map<unsigned long long, unordered_map<unsigned long long, int> > > mp;

int main()
{
    ios::sync_with_stdio(false);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int m, q;
    cin >> m >> q;
    string s[2];
    for(int i = 1;i <= m;i++)
    {
        cin >> s[0] >> s[1];
        if(s[0] == s[1])
        {
            continue;
        }
        int n = s[0].size(), lf = 0, rt = 0;
        for(int i = 0;i < n;i++)
        {
            if(s[0][i] != s[1][i])
            {
                lf = i;
                break;
            }
        }
        for(int i = n - 1;i >= 0;i--)
        {
            if(s[0][i] != s[1][i])
            {
                rt = i;
                break;
            }
        }
        unsigned long long hl = 0, hm = 0, hr = 0;
        for(int i = lf - 1;i >= 0;i--)
        {
            hl = (unsigned long long)(((__uint128_t)hl * base % mod + s[0][i] - 'a' + 1) % mod);
        }
        for(int i = lf;i <= rt;i++)
        {
            hm = (unsigned long long)(((__uint128_t)hm * base % mod + s[0][i] - 'a' + 1) % mod);
        }
        for(int i = lf;i <= rt;i++)
        {
            hm = (unsigned long long)(((__uint128_t)hm * base % mod + s[1][i] - 'a' + 1) % mod);
        }
        for(int i = rt + 1;i < n;i++)
        {
            hr = (unsigned long long)(((__uint128_t)hr * base % mod + s[1][i] - 'a' + 1) % mod);
        }
        mp[hm][hl][hr]++;
    }
    while(q--)
    {
        cin >> s[0] >> s[1];
        if(s[0].size() != s[1].size())
        {
            printf("0\n");
            continue;
        }
        int n = s[0].size(), lf = 0, rt = 0;
        for(int i = 0;i < n;i++)
        {
            if(s[0][i] != s[1][i])
            {
                lf = i;
                break;
            }
        }
        for(int i = n - 1;i >= 0;i--)
        {
            if(s[0][i] != s[1][i])
            {
                rt = i;
                break;
            }
        }
        unsigned long long hl = 0, hm = 0, hr = 0;
        for(int i = lf;i <= rt;i++)
        {
            hm = (unsigned long long)(((__uint128_t)hm * base % mod + s[0][i] - 'a' + 1) % mod);
        }
        for(int i = lf;i <= rt;i++)
        {
            hm = (unsigned long long)(((__uint128_t)hm * base % mod + s[1][i] - 'a' + 1) % mod);
        }
        unordered_set<unsigned long long> st;
        st.insert(0);
        for(int i = rt + 1;i < n;i++)
        {
            hr = (unsigned long long)(((__uint128_t)hr * base % mod + s[1][i] - 'a' + 1) % mod);
            st.insert(hr);
        }
        int res = 0;
        if(__builtin_expect(mp[hm].count(0), false))
        {
            for(pair<unsigned long long, int> i : mp[hm][0])
            {
                if(__builtin_expect(st.count(i.first), false))
                {
                    res += i.second;
                }
            }
        }
        for(int i = lf - 1;i >= 0;i--)
        {
            hl = (unsigned long long)(((__uint128_t)hl * base % mod + s[0][i] - 'a' + 1) % mod);
            if(__builtin_expect(mp[hm].count(hl), false))
            {
                for(pair<unsigned long long, int> i : mp[hm][hl])
                {
                    if(__builtin_expect(st.count(i.first), false))
                    {
                        res += i.second;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
