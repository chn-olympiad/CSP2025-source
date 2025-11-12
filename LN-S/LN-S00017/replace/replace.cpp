#include<bits/stdc++.h>
using namespace std;
#define up(s, e, i) for (int i = (s); i <= (e); i++)
#define down(s, e, i) for (int i = (s); i >= (e); i--)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define ull unsigned long long

namespace Main
{
    const int N = 200010;
    const ull base = 131;
    vector<ull> gen_hash(string s)
    {
        ull h = 0;
        vector<ull> ans;
        for(auto i: s)
        {
            h *= base, h += i;
            ans.push_back(h);
        }
        return ans;
    }
    int bj(const string &s, const vector<ull> &hs, const string &t, const vector<ull> &ht)
    {
        if(s.size() == 0 && t.size() == 0) return 0;
        if(s.size() == 0) return 1;
        if(t.size() == 0) return -1;
        int l = 0, r = min(s.size(), t.size()) - 1, res = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(hs[mid] != ht[mid]) r = mid - 1;
            else l = mid + 1, res = mid;
        }
        if(res == s.size() - 1 && res == t.size() - 1) return 0;
        if(res == s.size() - 1) return 1;
        if(res == t.size() - 1) return -1;
        return s[res + 1] < t[res + 1] ? 1 : -1;
    }
    bool check_pre(const string &s, const vector<ull> &hs, const string &t, const vector<ull> &ht)
    {
        if(s.size() == 0 && t.size() == 0) return 1;
        if(s.size() == 0) return 1;
        if(t.size() == 0) return -1;
        int l = 0, r = min(s.size(), t.size()) - 1, res = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(hs[mid] != ht[mid]) r = mid - 1;
            else l = mid + 1, res = mid;
        }
        return res == s.size() - 1;
    }
    struct X
    {
        string s, t, a, b;
        vector<ull> hs, ht, ha, hb;
        X() {}
        X(string s, string t, string a, string b): s(s), t(t), a(a), b(b)
        {
            hs = gen_hash(s), ht = gen_hash(t), ha = gen_hash(a), hb = gen_hash(b);
        }
        bool operator <(const X &y) const
        {
            if(bj(s, hs, y.s, y.hs)) return bj(s, hs, y.s, y.hs) == 1 ? 1 : 0;
            if(bj(t, ht, y.t, y.ht)) return bj(t, ht, y.t, y.ht) == 1 ? 1 : 0;
            if(bj(a, ha, y.a, y.ha)) return bj(a, ha, y.a, y.ha) == 1 ? 1 : 0;
            return 0;
        }
    };
    X get(string s1, string s2)
    {
        int m = s1.size();
        s1 = " " + s1, s2 = " " + s2;
            
        int l = 0, r = 0;
        up(1, m, i) if(s1[i] != s2[i])
        {
            l = i;
            break;
        }
        down(m, 1, i) if(s1[i] != s2[i])
        {
            r = i;
            break;
        }
        string s = s1.substr(l, r - l + 1), t = s2.substr(l, r - l + 1);
        string a, b;
        down(l - 1, 1, i) a += s1[i];
        up(r + 1, m, i) b += s1[i];
        return X(s, t, a, b);
    }
    bool check(const X &a, const X &b)
    {
        if(bj(a.s, a.hs, b.s, b.hs) || bj(a.t, a.ht, b.t, b.ht)) return 0;
        return check_pre(a.a, a.ha, b.a, b.ha);
    }
    pair<X, int> A[N];
    vector<pair<ull, int>> chg[N];
    int ans[N], o[N];
    int n, q;
    void main()
    {
        freopen("replace.in", "r", stdin);
        freopen("replace.out", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
        cin >> n >> q;
        vector<X> vec;
        up(1, n, j)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (s1 == s2)
                continue;
            vec.push_back(get(s1, s2));
        }

        up(1, q, i)
        {
            string s1, s2;
            cin >> s1 >> s2;
            A[i] = {get(s1, s2), i};
        }
        sort(A + 1, A + 1 + q);
        for (auto a : vec)
        {
            int L = -1;
            int l = 1, r = q;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                if(!(A[mid].first < a)) L = mid, r = mid - 1;
                else l = mid + 1;
            }
            if(L == -1) continue;
            l = L, r = q;
            int R = L - 1;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                if(check(a, A[mid].first)) R = mid, l = mid + 1;
                else r = mid - 1;
            }
            
            if (L <= R)
            {
                if(a.b.size() == 0) ans[L]++, ans[R + 1]--;
                else 
                {
                    chg[L].push_back({a.hb.back(), 1});
                    chg[R + 1].push_back({a.hb.back(), -1});
                }
            }
        }
        up(1, q, i) ans[i] += ans[i - 1];
        map<ull, int> mp;
        up(1, q, i)
        {
            for(auto x: chg[i]) mp[x.first] += x.second;
            for(auto j: A[i].first.hb)
                ans[i] += mp[j];
            o[A[i].second] = ans[i];
        }
        up(1, q, i) cout << o[i] << endl;
    }
};

int main()
{
    Main::main();
    return 0;
}

// g++ replace.cpp -o replace -O2 -std=c++14 && ./replace