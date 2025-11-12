#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q,fl[N],len[N],tot[N],cnt1,all,ans[N],cnt0;
string s[N][2],t[N][2];
bitset <N> bit,bit1,bit2;
vector <pair <int,int> > v;
unordered_map <string,int> mp;
struct node {
    int id,pl,pr;
    string str[2];
    pair <int,int> p;
    bool operator < (node nd) const {
        return p < nd.p;
    }
} ask[N],give[N];
struct Trie {
    int trie[5000010][26],cur = 1;
    vector <int> v[5000010];
    void insert(string s,int op,int id) {
        int p = 1,len = s.length();
        for(int i = 0;i < len;i++) {
            int tmp = s[i] - 'a';
            if(!trie[p][tmp]) trie[p][tmp] = ++cur;
            p = trie[p][tmp];
        }
        v[p].push_back(op * id);
    }
} tr;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> s[i][0] >> s[i][1];
        len[i] = s[i][0].length();
        int pl = len[i],pr = 0;
        for(int j = 0;j < len[i];j++) {
            if(s[i][0][j] == s[i][1][j]) continue;
            pl = j; break;
        }
        for(int j = len[i] - 1;~j;j--) {
            if(s[i][0][j] == s[i][1][j]) continue;
            pr = j; break;
        }
        if(pl == len[i] && pr == 0) continue;
        cnt0++; give[cnt0].id = i;
        give[cnt0].pl = pl; give[cnt0].pr = pr;
        for(int j = pl;j <= pr;j++) {
            give[cnt0].str[0] += s[i][0][j];
            give[cnt0].str[1] += s[i][1][j];
        }
    }
    for(int i = 1;i <= q;i++) {
        cin >> t[i][0] >> t[i][1];
        if(t[i][0].length() != t[i][1].length()) fl[i] = 1;
        else {
            tot[i] = t[i][0].length();
            int pl = tot[i],pr = 0;
            for(int j = 0;j < tot[i];j++) {
                if(t[i][0][j] == t[i][1][j]) continue;
                pl = j; break;
            }
            for(int j = tot[i] - 1;j >= 0;--j) {
                if(t[i][0][j] == t[i][1][j]) continue;
                pr = j; break;
            }
            if(pl == tot[i] && pr == 0) continue;
            cnt1++; ask[cnt1].id = i;
            ask[cnt1].pl = pl; ask[cnt1].pr = pr;
            for(int j = pl;j <= pr;j++) {
                ask[cnt1].str[0] += t[i][0][j];
                ask[cnt1].str[1] += t[i][1][j];
            }
        }
    }
    for(int i = 1;i <= cnt0;i++) {
        string s0 = give[i].str[0];
        pair <int,int> p;
        if(!mp.count(s0)) mp[s0] = ++all;
        p.first = mp[s0];
        s0 = give[i].str[1];
        if(!mp.count(s0)) mp[s0] = ++all;
        p.second = mp[s0];
        give[i].p = p;
    }
    sort(give + 1,give + cnt0 + 1);
    for(int i = 1;i <= cnt1;i++) {
        string s0 = ask[i].str[0];
        pair <int,int> p;
        if(!mp.count(s0)) mp[s0] = ++all;
        p.first = mp[s0];
        s0 = ask[i].str[1];
        if(!mp.count(s0)) mp[s0] = ++all;
        p.second = mp[s0];
        ask[i].p = p;
    }
    sort(ask + 1,ask + cnt1 + 1);
    for(int i = 1;i <= cnt0;i++) {
        string s1 = "",s2 = "";
        int x = give[i].id,pl = give[i].pl,pr = give[i].pr;
        for(int j = pl - 1;j >= 0;--j) s1 += s[x][0][j];
        for(int j = pr + 1;j < len[x];j++) s2 += s[x][0][j];
        tr.insert(s1,-1,give[i].id); tr.insert(s2,1,give[i].id);
    }
    for(int i = 1;i <= tr.cur;i++)
        sort(tr.v[i].begin(),tr.v[i].end());
    int j = 1;
    for(int i = 1;i <= cnt1;i++) {
        if(ask[i].p != ask[i - 1].p) {
            bit.reset(0); int pre = j;
            while(j <= cnt0 && give[j].p < ask[i].p) ++j;
            int k = j;
            while(k <= cnt0 && give[k].p == give[j].p)
                bit[give[k].id] = 1,k++;
        }
        if(give[j].p != ask[i].p) continue;
        int x = ask[i].id,pl = ask[i].pl,pr = ask[i].pr;
        string s1 = "",s2 = "";
        for(int j = pl - 1;j >= 0;--j) s1 += t[x][0][j];
        for(int j = pr + 1;j < tot[x];j++) s2 += t[x][0][j];
        int now = 1; bit1.reset(0); bit2 = bit;
        x = lower_bound(tr.v[now].begin(),tr.v[now].end(),0) - tr.v[now].begin();
        for(int j = 0;j < x;j++) bit1[-tr.v[now][j]] = 1;
        for(int j = 0;j < pl;j++) {
            int tmp = s1[j] - 'a';
            now = tr.trie[now][tmp];
            if(!now) break;
            x = lower_bound(tr.v[now].begin(),tr.v[now].end(),0) - tr.v[now].begin();
            for(int k = 0;k < x;k++) bit1[-tr.v[now][k]] = 1;
        }
        bit2 &= bit1;
        now = 1; bit1.reset(0); int siz = tr.v[now].size();
        x = lower_bound(tr.v[now].begin(),tr.v[now].end(),0) - tr.v[now].begin();
        for(int j = x;j < siz;j++) bit1[tr.v[now][j]] = 1;
        for(int j = 0;j < tot[ask[i].id] - pr - 1;j++) {
            int tmp = s2[j] - 'a';
            now = tr.trie[now][tmp];
            if(!now) break;
            siz = tr.v[now].size();
            x = lower_bound(tr.v[now].begin(),tr.v[now].end(),0) - tr.v[now].begin();
            for(int k = x;k < siz;k++) bit1[tr.v[now][k]] = 1;
        }
        bit2 &= bit1;
        ans[ask[i].id] = bit2.count();
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << "\n";
    return 0;
}
