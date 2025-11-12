#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int ll
using namespace std;
using ll = long long;
using ull = unsigned ll;
using puu = pair<ull, ull>;
using pii = pair<int, int>;
const int N = 2e5 + 5;
const int S = 5e6 + 5;
const int C = 26;
const int B1 = 131;
const int B2 = 1331;
const int Md = 998244353;
bool __st__;
int n, q, qcnt;
string a[N], b[N];
string qa, qb;
// puu ha[N], hb[N];
// struct Trie
// {
//     struct node
//     {
//         int nxt[C];
//         int sum, tot;
//     } seg[S];
//     int ncnt;
//     Trie() : ncnt(1) {}
//     void ins(const string &s, int val = 1)
//     {
//         int u = 1;
//         for (char c : s)
//         {
//             int tmp = c - 'a';
//             if (!seg[u].nxt[tmp])
//                 seg[u].nxt[tmp] = ++ncnt;
//             u = seg[u].nxt[tmp];
//             seg[u].tot += val;
//         }
//         seg[u].sum += val;
//     }
//     int qry(const string &s)
//     {
//         int u = 1;
//         for (char c : s)
//         {
//             int tmp = c - 'a';
//             if (!seg[u].nxt[tmp])
//                 return 0;
//             u = seg[u].nxt[tmp];
//             if (!seg[u].tot)
//                 return 0;
//         }
//         return seg[u].sum;
//     }
// } T;
bool __ed__;
void PrintMemUse() { cerr << (&__st__ - &__ed__) / 1048576.0 << '\n'; }
signed main()
{
    FASTIO;
    // PrintMemUse(); ?
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> qa >> qb;
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            int qal = qa.length();
            for (int k = 0; k + (int)a[j].length() <= qal; k++)
            {
                bool ok = 1;
                for (int l = 1; l <= (int)a[j].length() && ok; l++)
                    if (qa[k + l - 1] != a[j][l - 1] || qb[k + l - 1] != b[j][l - 1])
                        ok = 0;
                if (!ok)
                    continue;
                for (int l = 0; l < qal; l++ && ok)
                    if ((l < k || l > k + (int)a[j].length()) && qa[l] != qb[l])
                        ok = 0;
                ans += ok;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
g++ replace.cpp -o replace.exe -std=c++14 -O2 '-Wl,--stack=536870912' -Wall
./replace.exe

*/