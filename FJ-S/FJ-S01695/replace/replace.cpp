#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5, B = 131, mod = 1e9 + 7;
const int Bb = 1331, modd = 1e9 + 9;
int n, q;
int tr[M][26], tot, ans[N], top, cnt;
char s[M], t[M], S[M], T[M];
int id[N], idr[N], iol[N], ior[N], st[M];
pair<int, int> op[N],zp[M];
vector<int>e[M];
pair<pair<pair<int, int>, pair<int, int> >, int>up[N];
pair<pair<int, int>, pair<int, int> >upp[N];
void add(int l, int r, int val){
    int tp = 0;e[tp].push_back(val);
    while(l < r){
        if(!tr[tp][t[l] - 'a'])tr[tp][t[l] - 'a'] = ++tot;
        tp = tr[tp][t[l] - 'a'], ++l;
        e[tp].push_back(val), st[++top] = tp;
    }
}
void qry(int l, int r, int p){
    int tp = 0;
    while(l < r){
        if(!tr[tp][s[l] - 'a'])return;
        tp = tr[tp][s[l] - 'a'], ++l;
    }
    for(auto x : e[tp]){++ans[x];}
}
void kp(int n, int nw){
    int rr = n;
    for(;rr;--rr)if(S[rr] != T[rr])break;
    idr[nw] = idr[nw - 1],id[nw] = idr[nw] + 1;
    for(int i = rr + 1;i <= n;++i)s[++idr[nw]] = S[i];
    pair<pair<int, int>, pair<int, int> >dd = {{0, 0}, {0, 0}};
    for(;rr;--rr){
        //cerr << S[rr] << '\n';
        dd.first = {(1ll * dd.first.first * B + (S[rr] - 'a' + 1)) % mod, (1ll * dd.first.second * Bb + (S[rr] - 'a' + 1)) % modd};
        dd.second = {(1ll * dd.second.first * B + (T[rr] - 'a' + 1)) % mod, (1ll * dd.second.second * Bb + (T[rr] - 'a' + 1)) % modd};
    }
    up[nw] = {dd, nw};
}
void pp(int n, int nw){
    int rr = n, ll = 1;
    for(;rr;--rr)if(S[rr] != T[rr])break;
    for(;ll <= n;++ll)if(S[ll] != T[ll])break;
    ior[nw] = ior[nw - 1],iol[nw] = ior[nw] + 1;
    for(int i = rr + 1;i <= n;++i)t[++ior[nw]] = S[i];
    pair<pair<int, int>, pair<int, int> >dd = {{0, 0}, {0, 0}};
    for(;rr;--rr){
        dd.first = {(1ll * dd.first.first * B + (S[rr] - 'a' + 1)) % mod, (1ll * dd.first.second * Bb + (S[rr] - 'a' + 1)) % modd};
        dd.second = {(1ll * dd.second.first * B + (T[rr] - 'a' + 1)) % mod, (1ll * dd.second.second * Bb + (T[rr] - 'a' + 1)) % modd};
        if(rr <= ll){
            int idd = lower_bound(upp + 1, upp + tot + 1, dd) - upp;
            if(upp[idd] == dd){
                zp[++cnt] = {idd, nw};
                //cerr << nw << ' ' << idd << '\n';
            }
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for(int i = 1;i <= n;++i){
        scanf("%s%s", S + 1, T + 1);
        //if((S[1] == 'm') && (T[1] == 'd'))cerr << S + 1 << ' ' << T + 1 << '\n';
        kp(strlen(S + 1), i);
    }
    sort(up + 1, up + n + 1);
    for(int i = 1;i <= n;++i){
        if(up[i].first != up[i - 1].first)upp[++tot] = up[i].first;
        op[i] = {tot, up[i].second};
        //cerr << tot << ' ' << op[i].second <<' '<< (up[i].first.first.first)<<'\n';
    }
    for(int i = 1;i <= q;++i){
        scanf("%s%s", S + 1, T + 1);
        if(strlen(S + 1) == strlen(T + 1))pp(strlen(S + 1), i);
    }
    sort(zp + 1, zp + cnt + 1);
    for(int p = 1, s = 1, t = 1;p <= tot;++p){
        while(zp[s].first < p && s <= cnt)++s;
        while(op[t].first < p && t <= n)++t;
        top = 0;
        while(zp[s].first == p && s <= cnt)add(iol[zp[s].second], ior[zp[s].second], zp[s].second), ++s;
        while(op[t].first == p && t <= n){
            qry(id[t], idr[t], p), ++t;
        }
        for(int i = 0;i <= top;++i)e[i].clear();
    }
    for(int i = 1;i <= q;++i)printf("%d\n", ans[i]);
    return 0;
}