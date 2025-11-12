#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

const int MAX_N = 2e5+5, MAX_L = 5e6+5;
const LL B1 = 89, B2 = 471, P1 = 194910019, P2 = 1e9+7;

LL b1[MAX_L], b2[MAX_L];

struct my_Hash {
    LL h1, h2;

    my_Hash () {
        h1 = h2 = 0;
    }

    my_Hash (LL h1, LL h2) {
        this->h1 = h1;
        this->h2 = h2;
    }

    friend bool operator == (const my_Hash &x, const my_Hash &y) {
        return x.h1 == y.h1 && x.h2 == y.h2;
    }

    friend bool operator != (const my_Hash &x, const my_Hash &y) {
        return !(x == y);
    }
};

inline my_Hash sub_hash (int l, int r, const my_Hash *h) {
    if(l == 0) return h[r];
    LL h1 = (h[r].h1 - h[l-1].h1 * b1[r-l+1]) % P1;
    if(h1 < 0) h1 += P1;
    LL h2 = (h[r].h2 - h[l-1].h2 * b2[r-l+1]) % P2;
    if(h2 < 0) h2 += P2;
    return my_Hash(h1, h2);
}

inline my_Hash sub_hash (int l, int r, const vector<my_Hash> &h) {
    if(l == 0) return h[r];
    LL h1 = (h[r].h1 - h[l-1].h1 * b1[r-l+1]) % P1;
    if(h1 < 0) h1 += P1;
    LL h2 = (h[r].h2 - h[l-1].h2 * b2[r-l+1]) % P2;
    if(h2 < 0) h2 += P2;
    return my_Hash(h1, h2);
}

struct Tihuan {
    string s1, s2;
    int len, l, r;
    vector<my_Hash> h_s1, h_s2;

    Tihuan () {
        s1 = s2 = "";
        len = l = r = 0;
        h_s1.clear();
        h_s2.clear();
    }

    void init (string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        len = s1.size();
        h_s1.resize(len);
        h_s2.resize(len);
        h_s1.at(0) = my_Hash(s1.at(0)-'a'+1, s1.at(0)-'a'+1);
        h_s2.at(0) = my_Hash(s2.at(0)-'a'+1, s2.at(0)-'a'+1);
        l = r = -1;
        for(int i = 0; i <= len-1; i ++) {
            if(i >= 1) {
                h_s1.at(i) = my_Hash((h_s1.at(i-1).h1*B1+s1.at(i)-'a'+1)%P1, (h_s1.at(i-1).h2*B2+s1.at(i)-'a'+1)%P2);
                h_s2.at(i) = my_Hash((h_s2.at(i-1).h1*B1+s2.at(i)-'a'+1)%P1, (h_s2.at(i-1).h2*B2+s2.at(i)-'a'+1)%P2);
            }
            if(s1.at(i) != s2.at(i) && l == -1) {
                l = i;
            }
        }
        for(int i = len-1; i >= 0; i --) {
            if(r == -1 && s1.at(i) != s2.at(i)) {
                r = i;
                break;
            }
        }
    }
}a[MAX_N];

int n, q;

namespace t3_try_1 {

    Tihuan t;

    void run () {
        while(q --) {
            string t1, t2;
            cin >> t1 >> t2;
            if(t1.size() != t2.size()) {
                printf("0\n");
                continue;
            }
            t.init(t1, t2);
            LL ans = 0;
            for(int i = 1; i <= n; i ++) {
                //printf("i = %d  tl = %d  tr = %d  al = %d  ar = %d\n",i,t.l,t.r,a[i].l,a[i].r);
                if(t.r-t.l+1 > a[i].r-a[i].l+1) continue;
                int l = t.l - a[i].l, r;
                r = l + a[i].len - 1;
                //printf("i = %d  l = %d  r = %d\n",i,l,r);
                if(l < 0 || r < 0 || r >= t.len) continue;
                if(sub_hash(0, a[i].len-1, a[i].h_s1) == sub_hash(l, r, t.h_s1) && sub_hash(0, a[i].len-1, a[i].h_s2) == sub_hash(l, r, t.h_s2)) {
                    if(l <= t.l && t.r <= r) ++ ans;
                }
            }
            printf("%lld\n",ans);
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    b1[0] = b2[0] = 1;
    for(int i = 1; i <= MAX_L - 3; i ++) {
        b1[i] = b1[i-1] * B1 % P1;
        b2[i] = b2[i-1] * B2 % P2;
    }
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        string x, y;
        cin >> x >> y;
        a[i].init(x, y);
    }
    t3_try_1::run();
    return 0;
}
