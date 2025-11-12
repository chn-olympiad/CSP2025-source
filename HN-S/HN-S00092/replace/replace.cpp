#include<bits/stdc++.h>

using namespace std;

using LL = long long;

using bigint = __int128;

const int N = 1e7 + 5, M = 2e5 + 5;
const int B = 1145141;
const LL P = 1e18 + 3;

struct TRIE{
  int son[26];
}trie[N];

struct Node{
  string a, b;
  LL c, d;
}a[M], b[M];

struct node{
  string a, b;
  int c;
};

vector<node>g[M];
int n, q, tot, top[N], sz[N], son[N], ccnt, fa[N], dfn[N], c[N], ans[N], rt[4], cyx[N], ly[N];
vector<int>mp[N];
string s1, s2;
pair<LL, LL>to_[N];

int Push_back(){
  ++ccnt;
  son[ccnt] = 0;
  mp[ccnt].clear();
  for(int j = 0; j < 26; ++j)trie[ccnt].son[j] = 0;
  return ccnt;
}

void Insert(int u, string s, int id){
  for(auto c : s){
    if(!trie[u].son[c - 'a'])trie[u].son[c - 'a'] = Push_back();
    u = trie[u].son[c - 'a'];
  }
  //if(306 == id)cout << "WHY " << u <<'\n';
  mp[u].push_back(id);
}

void dfs(int x){
  sz[x] = 1, son[x] = 0;
  //if(x == 7 || x == 1)cout << "GOOD " << mp[x].size() << '\n';
  for(int i = 0; i < 26; ++i){
    if(trie[x].son[i]){
      fa[trie[x].son[i]] = x;
      //if(trie[x].son[i] == 1 || trie[x].son[i] == 7)cout << x << ' ' << i << "HHH\n";
      dfs(trie[x].son[i]);
      if(sz[trie[x].son[i]] > sz[son[x]])son[x] = trie[x].son[i];
      sz[x] += sz[trie[x].son[i]];
    }
  }
}

void dfs2(int x){
  //if(x == 7 || x == 1)cout << "FUNNy " << mp[x].size() << '\n';
  dfn[x] = ++tot;
  ly[tot] = x;
  for(auto v : mp[x]){
    cyx[v] = tot;
  }
  //if(x == 2)cout << "GGG " << trie[x].son[18] << ' ' << son[x] << '\n';
  if(son[x]){
    top[son[x]] = x;
    dfs2(son[x]);
  }
  for(int i = 0; i < 26; ++i){
    if(trie[x].son[i] && trie[x].son[i] != son[x]){
      top[trie[x].son[i]] = trie[x].son[i];
      dfs2(trie[x].son[i]);
    }
  }
}

void updata(int p, int k){
  for(; p <= tot; c[p] += k, p += (p & -p)){
  }
}

int getsum(int p){
  int res = 0;
  for(; p; res += c[p], p -= (p & -p)){
  }
  return res;
}

int Getsum(int x){
  int res = 0;
  for(; x; x = fa[top[x]]){
    res += getsum(dfn[x]) - getsum(dfn[top[x]] - 1);
  }
  return res;
}

void Dfs(int x){
  //cout << x <<'\n';
  //exit(0);
  for(auto v : mp[x]){
    //cout << "!!! " << v << ' ' << cyx[v] << ' ' << n << ' ' << cyx[v] << '\n';
    if(v <= n)updata(cyx[v], 1);
    else ans[v - n] = Getsum(ly[cyx[v]]);
    //cout << "CYX AKIOI\n";
  }
  //exit(0);
  for(int i = 0; i < 26; ++i){
    if(trie[x].son[i]){
      Dfs(trie[x].son[i]);
    }
  }
  for(auto v : mp[x]){
    if(v <= n)updata(cyx[v], -1);
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  for(int i = 1; i <= n; ++i){
    cin >> s1 >> s2;
    if(s1 == s2)continue;
    int l = 0, r = s1.size() - 1;
    for(; s1[l] == s2[l]; l++){
    }
    for(; s1[r] == s2[r]; r--){
    }
    tot++;
    for(int j = 0; j < l; ++j){
      a[tot].a += s1[j];
    }
    for(int j = r + 1; j < s1.size(); j++){
      a[tot].b += s1[j];
    }
    reverse(a[tot].a.begin(), a[tot].a.end());
    for(int j = l; j <= r; j++){
      a[tot].c = ((bigint)(a[tot].c) * B + s1[j] - 'a' + 1) % P;
      a[tot].d = ((bigint)(a[tot].d) * B + s2[j] - 'a' + 1) % P;
      //cout << s1[j] << ' ';
    }
    //cout << '\n';
  }
  n = tot;
  sort(a + 1, a + n + 1, [](const Node &i, const Node &j){  return i.c < j.c || i.c == j.c && i.d < j.d; });
  for(int i = 1; i <= n; ++i){
    to_[i] = {a[i].c, a[i].d};
    //cout << a[i].c << ' ' << a[i].d << '\n';
  }
  for(int i = 1; i <= q; ++i){
    cin >> s1 >> s2;
    int l = 0, r = s1.size() - 1;
    for(; s1[l] == s2[l]; l++){
    }
    for(; s1[r] == s2[r]; r--){
    }
    for(int j = 0; j < l; j++){
      b[i].a += s1[j];
    }
    for(int j = r + 1; j < s1.size(); j++){
      b[i].b += s2[j];
    }
    reverse(b[i].a.begin(), b[i].a.end());
    for(int j = l; j <= r; ++j){
      b[i].c = ((bigint)(b[i].c) * B + s1[j] - 'a' + 1) % P;
      b[i].d = ((bigint)(b[i].d) * B + s2[j] - 'a' + 1) % P;
    }
    //cout << l << ' ' << b[i].c << ' ' << b[i].d << '\n';
    l = lower_bound(to_ + 1, to_ + n + 1, (pair<LL, LL>){b[i].c, b[i].d}) - to_;
    if(to_[l].first != b[i].c || to_[l].second != b[i].d || l > n)continue;
    //cout << l << '\n';
    g[l].push_back({b[i].a, b[i].b, i});
    //cout << l << '\n';
  }
  for(int i = 1, j = 1; i <= n; i = j){
    ccnt = 0;
    rt[0] = Push_back(), rt[1] = Push_back();
    for(; j <= n &&(a[i].c == a[j].c && a[i].d == a[j].d); ++j){
      Insert(rt[0], a[j].a, j);
      Insert(rt[1], a[j].b, j);
    }
    for(auto [s1, s2, id] : g[i]){
      Insert(rt[0], s1, id + n);
      Insert(rt[1], s2, id + n);
    }
    //cout << i << ' ' << j << ' ' <<a[i].a << ' ' << a[i].b << ' ' << a[j].a << ' ' << a[j].b << '\n';
    //if(j == n + 1)return 0;
    tot = 0;
    dfs(rt[1]);
    top[rt[1]] = rt[1];
    dfs2(rt[1]);
    for(int j = 1; j <= tot; ++j){
      c[j] = 0;
    }
    Dfs(rt[0]);
    //cout <<"OK?\n";
  }
  for(int i = 1; i <= q; ++i){
    cout << ans[i] << '\n';
  }
  return 0;
}
/*
2 1
aab aab
bbaaa abbab
aba bba
*/
