#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

mt19937_64 MT(time(nullptr));
const u64 rmsk = MT();
u64 pool[5000005];
struct chash {
  inline u64 operator()(u64 x) const { return x ^ rmsk; }
};
unordered_map<u64, int, chash> mp;

constexpr int L = 5000005;
int n, q;

struct Trie {
  int tot, ch[L][27], fa[L], nx[L][27];
  int sum[L], fail[L];
  short up[L];
  inline void ins(int root, const string &s) {
    int u = root;
    for (int i = 0; i < s.size(); i++) {
      int d = s[i] - 'a' + 1;
      if (!ch[u][d]) ch[u][d] = ++tot, fa[ch[u][d]] = u, up[ch[u][d]] = d;
      u = ch[u][d];
    }
    sum[u]++;
  }
  int Q[L], ql, qr;
  inline void init(int root) {
    ql = 1, qr = 0;
    for (int d = 0; d <= 26; d++)
      if (ch[root][d]) Q[++qr] = ch[root][d];
    
    // cerr << "output trie " << root << "\n";
    while (ql <= qr) {
      int u = Q[ql++];
      // 计算 fail
      int p = fa[u], d = up[u];
      while (p != root && (!ch[p][d] || ch[p][d] == u)) p = fail[p];
      if (!ch[p][d] || ch[p][d] == u) fail[u] = root;
      else fail[u] = ch[p][d];
      
      sum[u] += sum[fail[u]];
      // cerr << "    " << u << " " << fa[u] << " " << up[u] << " " << fail[u] << " : " << p << " " << ch[p][d] << " " << up[fail[u]] << "\n" << flush;
      
      for (int d = 0; d <= 26; d++)
        if (ch[u][d]) Q[++qr] = ch[u][d];
    }
  }
  inline int qry(int root, const string &s) { // 计算子串数量
    int u = root;
    int res = 0; // 这里每个子串最多出现一次，不可能溢出
    for (int i = 0; i < s.size(); i++) {
      int d = s[i] - 'a' + 1;
      while (u != root && !ch[u][d]) u = fail[u];
      if (ch[u][d]) u = ch[u][d];
      res += sum[u];
    }
    return res;
  }
} trie;
vector<int> all; // 所有的 trie

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cerr << sizeof(trie) << "\n" << flush;
  
  // 初始化随机值
  for (int i = 0; i < 5000000; i++) pool[i] = MT();
  
  // 输入替换方案，建立自动机
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    int l = 0, r = (int)s1.size() - 1;
    while (l < s1.size() && s1[l] == s2[l]) l++;
    while (r >= 0 && s1[r] == s2[r]) r--;
    if (l <= r) { // 因为 t_1\ne t_2，所以这样的串才有用
      u64 h = 0; // 不一样部分哈希
      for (int i = l; i <= r; i++) h ^= pool[i - l] * s1[i];
      for (int i = l; i <= r; i++) h ^= pool[i - l + r - l + 1] * s2[i];
      for (int i = l; i <= r; i++) s1[i] = 'a' - 1;
      // 加入 trie
      int root = mp[h];
      if (!root) root = mp[h] = ++trie.tot, all.emplace_back(root); // 新的字典树
      trie.ins(root, s1);
    }
  }
  
  // cerr << "end build " << trie.tot << "\n" << flush;
  
  // 初始化 trie 自动机
  for (int root : all) trie.init(root);
  
  // cerr << "end init " << trie.tot << "\n" << flush;
  
  // 处理查询
  for (int i = 1; i <= q; i++) {
    string t1, t2;
    cin >> t1 >> t2;
    if (t1.size() != t2.size()) {
      cout << 0 << "\n";
      continue;
    }
    int l = 0, r = (int)t1.size() - 1;
    while (l < t1.size() && t1[l] == t2[l]) l++;
    while (r >= 0 && t1[r] == t2[r]) r--;
    assert(l <= r); // 题目保证一定有不一样的位置
    
    u64 h = 0; // 不一样部分哈希
    for (int i = l; i <= r; i++) h ^= pool[i - l] * t1[i];
    for (int i = l; i <= r; i++) h ^= pool[i - l + r - l + 1] * t2[i];
    for (int i = l; i <= r; i++) t1[i] = 'a' - 1;
    
    if (mp.find(h) == mp.end()) cout << "0\n";
    else cout << trie.qry(mp[h], t1) << "\n";
  }
  // cerr << clock() * 1000 / CLOCKS_PER_SEC << "\n";
  return 0;
}