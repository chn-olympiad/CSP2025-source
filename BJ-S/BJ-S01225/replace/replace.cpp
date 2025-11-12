#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int base = 149,base2 = 173;
int n,q,ans[200005],son[5200005][26],fail[5200005],tot,g[200005],c[5200005],cnt,ll,rr;
string s[200005][2],t[200005][2];
vector<int> v[5200005];
map<pair<ull,ull>,int> mp;
inline pair<ull,ull> hsh(string &x,string &y){
    ll = -1;
    for(int j = 0;j < x.length();j++){
        if(ll < 0 && x[j] != y[j]) ll = j;
        if(x[j] != y[j]) rr = j;
    }
    ull tmp = 0,tmp2 = 0;
    for(int j = ll;j <= rr;j++){
        tmp = tmp * base + x[j];
        tmp2 = tmp2 * base2 + y[j];
    }
    return {tmp,tmp2};
}
inline void ins(int p,int x,string &y){
    //cerr << p << '-';
    if(x == y.length()){
        c[p]++;
        return;
    }
    if(!son[p][y[x] - 'a']) son[p][y[x] - 'a'] = ++tot;
    ins(son[p][y[x] - 'a'],x + 1,y);
}
inline void build(int p){
    queue<int> q;
    for(int i = 0;i < 26;i++){
        if(!son[p][i]) son[p][i] = p;
        else{
            fail[son[p][i]] = p;
            v[p].push_back(son[p][i]);
            q.push(son[p][i]);
        }
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 0;i < 26;i++){
            if(!son[t][i]) son[t][i] = son[fail[t]][i];
            else{
                fail[son[t][i]] = son[fail[t]][i];
                v[son[fail[t]][i]].push_back(son[t][i]);
                q.push(son[t][i]);
            }
        }
    }
}
inline void dfs(int p){
    for(int i:v[p]){
        c[i] += c[p];
        dfs(i);
    }
}
inline int qry(int p,int beg,int lst,string &x){
    if(beg == lst) return c[p];
    return c[p] + qry(son[p][x[beg] - 'a'],beg + 1,lst,x);
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s[i][0] >> s[i][1];
        if(s[i][0] == s[i][1]) continue;
        pair<ull,ull> p = hsh(s[i][0],s[i][1]);
        if(!mp.count(p)) mp[p] = ++tot,g[++cnt] = tot;
        ins(mp[p],0,s[i][0]);
        //cerr << '\n';
    }
    for(int i = 1;i <= cnt;i++) build(g[i]),dfs(g[i]);
    for(int i = 1;i <= q;i++){
        cin >> t[i][0] >> t[i][1];
        if(t[i][0].length() != t[i][1].length()) continue;
        pair<ull,ull> p = hsh(t[i][0],t[i][1]);
        if(!mp.count(p)) continue;
        ans[i] = qry(mp[p],0,t[i][0].length(),t[i][0]);
        //cerr << ans[i] <<' ';
        ans[i] -= qry(mp[p],0,ll,t[i][0]) + qry(mp[p],rr + 1,t[i][0].length(),t[i][0]);
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}
