#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
const int MAXN = 200005,base = 313,MAXSIZ = 10000005;
int n,Q,ls[MAXN],rs[MAXN],lt[MAXN],rt[MAXN],ndc,son[MAXSIZ][26],dfncnt,dfn[MAXSIZ],siz[MAXSIZ],tol1[MAXN],tol2[MAXN],tor1[MAXN],tor2[MAXN],tot1[MAXN],tot2[MAXN],sum[MAXN << 1],trsiz,ans[MAXN];
unsigned long long hs[MAXN],ht[MAXN],h[MAXN << 1];
bool check[MAXSIZ];
array <int,5> op[MAXN * 3];
string s[MAXN][2],t[MAXN][2];
vector <int> gs[MAXN << 1],gt[MAXN << 1];
inline void build(){
    for(int j = 1;j <= ndc;j++){
        for(int k = 0;k < 26;k++){
            son[j][k] = 0;
        }
        check[j] = 0;
    }
    ndc = 1;
    dfncnt = 0;
}
inline int ins(int pos,int dep,string& x){
    if(dep == x.size()){
        check[pos] = 1;
        return pos;
    }
    if(!son[pos][x[dep] - 'a']){
        son[pos][x[dep] - 'a'] = ++ndc;
    }
    return ins(son[pos][x[dep] - 'a'],dep + 1,x);
}
inline void dfs(int pos){
    if(check[pos]){
        dfn[pos] = ++dfncnt;
        siz[pos] = 1;
    }
    else{
        siz[pos] = 0;
    }
    for(int i = 0;i < 26;i++){
        if(son[pos][i]){
            dfs(son[pos][i]);
            siz[pos] += siz[son[pos][i]];
        }
    }
}
inline int lowbit(int x){
    return x & -x;
}
inline void add(int pos,int x){
    for(;pos <= trsiz;pos += lowbit(pos)){
        sum[pos] += x;
    }
}
inline int qry(int pos){
    int ret = 0;
    for(;pos;pos ^= lowbit(pos)){
        ret += sum[pos];
    }
    return ret;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> Q;
    for(int i = 1;i <= n;i++){
        cin >> s[i][0] >> s[i][1];
        if(s[i][0] == s[i][1]){
            continue;
        }
        int psl,psr;
        for(int j = 0;j < s[i][0].size();j++){
            if(s[i][0][j] != s[i][1][j]){
                psl = j;
                break;
            }
        }
        for(int j = (int)s[i][0].size() - 1;~j;j--){
            if(s[i][0][j] != s[i][1][j]){
                psr = j;
                break;
            }
        }
        for(int j = psl;j <= psr;j++){
            hs[i] = hs[i] * base + s[i][0][j];
            hs[i] = hs[i] * base + s[i][1][j];
        }
        ls[i] = psl;
        rs[i] = psr;
        h[i] = hs[i];
    }
    for(int i = 1;i <= Q;i++){
        cin >> t[i][0] >> t[i][1];
        if(t[i][0].size() != t[i][1].size()){
            continue;
        }
        int psl,psr;
        for(int j = 0;j < t[i][0].size();j++){
            if(t[i][0][j] != t[i][1][j]){
                psl = j;
                break;
            }
        }
        for(int j = (int)t[i][0].size() - 1;~j;j--){
            if(t[i][0][j] != t[i][1][j]){
                psr = j;
                break;
            }
        }
        for(int j = psl;j <= psr;j++){
            ht[i] = ht[i] * base + t[i][0][j];
            ht[i] = ht[i] * base + t[i][1][j];
        }
        lt[i] = psl;
        rt[i] = psr;
        h[n + i] = ht[i];
    }
    sort(h + 1,h + 1 + n + Q);
    int len = unique(h + 1,h + 1 + n + Q) - h - 1;
    for(int i = 1;i <= n;i++){
        if(s[i][0] == s[i][1]){
            continue;
        }
        gs[lower_bound(h + 1,h + 1 + len,hs[i]) - h].push_back(i);
    }
    for(int i = 1;i <= Q;i++){
        if(t[i][0].size() != t[i][1].size()){
            continue;
        }
        gt[lower_bound(h + 1,h + 1 + len,ht[i]) - h].push_back(i);
    }
    for(int i = 1;i <= len;i++){
        build();
        for(int j = 0;j < gs[i].size();j++){
            int tmp = gs[i][j];
            string now = "";
            for(int k = ls[tmp] - 1;~k;k--){
                now += s[tmp][0][k];
            }
            tol1[j] = ins(1,0,now);
        }
        for(int j = 0;j < gt[i].size();j++){
            int tmp = gt[i][j];
            string now = "";
            for(int k = lt[tmp] - 1;~k;k--){
                now += t[tmp][0][k];
            }
            tot1[j] = ins(1,0,now);
        }
        dfs(1);
        for(int j = 0;j < gs[i].size();j++){
            int tmp = tol1[j];
            tol1[j] = dfn[tmp];
            tor1[j] = dfn[tmp] + siz[tmp] - 1;
        }
        for(int j = 0;j < gt[i].size();j++){
            tot1[j] = dfn[tot1[j]];
        }
        build();
        for(int j = 0;j < gs[i].size();j++){
            int tmp = gs[i][j];
            string now = "";
            for(int k = rs[tmp] + 1;k < s[tmp][0].size();k++){
                now += s[tmp][0][k];
            }
            tol2[j] = ins(1,0,now);
        }
        for(int j = 0;j < gt[i].size();j++){
            int tmp = gt[i][j];
            string now = "";
            for(int k = rt[tmp] + 1;k < t[tmp][0].size();k++){
                now += t[tmp][0][k];
            }
            tot2[j] = ins(1,0,now);
        }
        dfs(1);
        for(int j = 0;j < gs[i].size();j++){
            int tmp = tol2[j];
            tol2[j] = dfn[tmp];
            tor2[j] = dfn[tmp] + siz[tmp] - 1;
        }
        for(int j = 0;j < gt[i].size();j++){
            tot2[j] = dfn[tot2[j]];
        }
        trsiz = dfncnt;
        int optop = 0;
        for(int j = 0;j < gs[i].size();j++){
            op[++optop] = (array <int,5>){tol1[j],0,tol2[j],tor2[j],1};
            op[++optop] = (array <int,5>){tor1[j] + 1,0,tol2[j],tor2[j],-1};
        }
        for(int j = 0;j < gt[i].size();j++){
            op[++optop] = (array <int,5>){tot1[j],1,tot2[j],gt[i][j],0};
        }
        sort(op + 1,op + 1 + optop);
        for(int j = 1;j <= trsiz;j++){
            sum[j] = 0;
        }
        for(int j = 1;j <= optop;j++){
            if(!op[j][1]){
                add(op[j][2],op[j][4]);
                add(op[j][3] + 1,-op[j][4]);
            }
            else{
                ans[op[j][3]] = qry(op[j][2]);
            }
        }
    }
    for(int i = 1;i <= Q;i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
