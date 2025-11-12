#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 2e5 + 10, maxq = 2e5 + 10, maxlen = 5e6, bse = 19260817;

struct Tri{
    int a, b, c;
    constexpr Tri(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c){}
};

int n, q, tot = 0;
char s1[maxlen + 10], s2[maxlen + 10];
int lenp[maxn], lens[maxn], res[maxq];
unsigned long long a[maxn], b[maxn], pre[maxn], suf[maxn], valp[maxlen + 10], vals[maxlen + 10];
vector<pair<int, int> > tmp1[maxn + maxq];
vector<Tri> tmp2[maxn + maxq];
vector<int> tmp;
vector<int> ad[maxn + maxq];
vector<pair<int, int> > qry[maxn + maxq];
map<pair<int, int>, int> mp;

inline void calc(int len, int &lenp, int &lens, unsigned long long &pre, unsigned long long &suf, unsigned long long &a, unsigned long long &b){
    for (lenp = 0; s1[lenp + 1] == s2[lenp + 1]; lenp++);
    for (lens = 0; s1[len - lens] == s2[len - lens]; lens++);
    for (int i = 1; i <= lenp; pre = pre * bse + s1[lenp - i + 1], valp[i] = valp[i - 1] * bse + s1[lenp - i + 1], i++);
    for (int i = 1; i <= lens; suf = suf * bse + s1[len - lens + i], vals[i] = vals[i - 1] * bse + s1[len - lens + i], i++);
    for (int j = lenp + 1; j <= len - lens; j++){
        a = a * bse + s1[j], b = b * bse + s2[j];
    }
}
namespace BIT{
    int tree[maxn + maxq];
    inline int lbw(int x){
        return x & -x;
    }
    inline void add(int x){
        for (;x <= tmp.size(); tree[x]++, x += lbw(x));
    }
    inline int query(int x){
        int res = 0;
        for (;x; res += tree[x], x -= lbw(x));
        return res;
    }
}

using namespace BIT;

inline void pos(int &x){
    x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin() + 1;
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d %d", &n, &q);
    bool fl = true;
    for (int i = 1; i <= n; i++){
        scanf("%s %s", s1 + 1, s2 + 1);
        const int len = strlen(s1 + 1);
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int i = 1; i <= len; i++){
            s1[i] == 'a' ? cnt1++ : s1[i] == 'b' && cnt2++, s2[i] == 'a' ? cnt3++ : s2[i] == 'b' && cnt4++;
        }
        calc(len, lenp[i], lens[i], pre[i], suf[i], a[i], b[i]), fl &= cnt1 == len - 1 && cnt2 == 1 && cnt3 == len - 1 && cnt4 == 1, !mp[make_pair(a[i], b[i])] && (mp[make_pair(a[i], b[i])] = ++tot), tmp1[mp[make_pair(a[i], b[i])]].push_back(make_pair(lenp[i], lens[i]));
    }
    for (int i = 1; i <= q; i++){
        scanf("%s %s", s1 + 1, s2 + 1);
        const int len = strlen(s1 + 1);
        if (len != strlen(s2 + 1)){
            printf("0\n");
            continue;
        }
        int lpnow = 0, lsnow = 0, res = 0;
        unsigned long long pnow = 0, snow = 0, anow = 0, bnow = 0;
        calc(len, lpnow, lsnow, pnow, snow, anow, bnow);
        if (!fl){
            for (int j = 1; j <= n; j++){
                res += lpnow >= lenp[j] && lsnow >= lens[j] && valp[lenp[j]] == pre[j] && vals[lens[j]] == suf[j] && anow == a[j] && bnow == b[j];
            }
            printf("%d\n", res);
        }else{
            tmp2[mp[make_pair(anow, bnow)]].push_back(Tri(i, lpnow, lsnow));
        }
    }
    if (fl){
        for (auto hsh: mp){
            tmp.clear();
            for (auto x: tmp1[hsh.second]){
                tmp.push_back(x.first);
            }
            for (auto x: tmp2[hsh.second]){
                tmp.push_back(x.b);
            }
            sort(tmp.begin(), tmp.end()), tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            const int len = tmp.size();
            for (int i = 1; i <= len; i++){
                ad[i].clear(), qry[i].clear();
            }
            for (int i = 0; i < tmp1[hsh.second].size(); i++){
                pos(tmp1[hsh.second][i].first);
            }
            for (int i = 0; i < tmp2[hsh.second].size(); i++){
                pos(tmp2[hsh.second][i].b);
            }
            tmp.clear();
            for (auto x: tmp1[hsh.second]){
                tmp.push_back(x.second);
            }
            for (auto x: tmp2[hsh.second]){
                tmp.push_back(x.c);
            }
            sort(tmp.begin(), tmp.end()), tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            for (int i = 0; i < tmp1[hsh.second].size(); i++){
                pos(tmp1[hsh.second][i].second), ad[tmp1[hsh.second][i].first].push_back(tmp1[hsh.second][i].second);
            }
            for (int i = 0; i < tmp2[hsh.second].size(); i++){
                pos(tmp2[hsh.second][i].c), qry[tmp2[hsh.second][i].b].push_back(make_pair(tmp2[hsh.second][i].a, tmp2[hsh.second][i].c));
            }
            for (int i = 1; i <= tmp.size(); i++){
                tree[i] = 0;
            }
            for (int i = 1; i <= len; i++){
                for (auto x: ad[i]){
                    add(x);
                }
                for (auto x: qry[i]){
                    res[x.first] = query(x.second);
                }
            }
        }
        for (int i = 1; i <= q; i++){
            printf("%d\n", res[i]);
        }
    }

return 0;
}