#include <bits/stdc++.h>

constexpr int maxV = 27;

class ACAM {
  struct Node {
    int fail, cnt;
    std::array<int, maxV> trans;
    std::vector<std::pair<int, int>> tmp;
  };

  int tot;
  std::vector<Node> nodes;
  std::vector<std::string> buffer;

  void insert_(const std::string &S) {
    int p = 0;
    for (auto v: S) {
      int o = v - 'a';
      if (!nodes[p].trans[o]) { 
        nodes[p].tmp.emplace_back(o, tot);  
        nodes[p].trans[o] = tot++, nodes.emplace_back(); 
      }
      p = nodes[p].trans[o];
    }
    nodes[p].cnt++;
  }

public:
  explicit ACAM() : tot(1), nodes(1) {}

  void insert(const std::string &S) { buffer.emplace_back(S); }

  void build() {
    size_t buf = 1;
    for (const auto &v: buffer) { buf += v.length(); }
    nodes.reserve(buf);
    for (const auto &v: buffer) { insert_(v); }
    buffer.clear(), buffer.shrink_to_fit();
    assert(nodes.capacity() == buf);
    std::queue<int> que;
    for (auto v: nodes[0].trans) {
      if (v) { que.emplace(v); }
    }
    while (!que.empty()) {
      int u = que.front(), p = nodes[u].fail;
      que.pop(), nodes[u].cnt += nodes[p].cnt;
      nodes[u].trans = nodes[p].trans;
      for (auto t: nodes[u].tmp) {
        nodes[t.second].fail = nodes[u].trans[t.first];
        nodes[u].trans[t.first] = t.second;
        que.emplace(t.second);
      }
    }
  }

  int query(const std::string &S) {
    int ans = 0, p = 0;
    for (auto v: S) {
      int o = v - 'a';
      p = nodes[p].trans[o];
      ans += nodes[p].cnt;
    }
    return ans;
  }
};

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, Q;
  std::cin >> N >> Q;

  constexpr int pMod1 = 1E9 + 7, B1 = 131;
  constexpr int pMod2 = 998244353, B2 = 37;

  auto GetHash = [&](const std::string &S) {
    int s1 = 0, s2 = 0;
    for (auto v: S) {
      s1 = int((1LL * s1 * B1 + v) % pMod1);
      s2 = int((1LL * s2 * B2 + v) % pMod2);
    }
    // std::cerr << "HASH " << S << ' ' << s1 << ' ' << s2 << '\n';
    return std::make_pair(s1, s2);
  };

  int cnt = 0;
  std::vector<ACAM> acams;
  std::map<std::pair<int, int>, int> mp;

  for (int i = 0; i < N; i++) {
    std::string S, T;
    std::cin >> S >> T;
    if (S == T) { continue; }
    int l = -1, r = -1;
    for (int j = 0; j < (int) S.length(); j++) {
      if (S[j] != T[j]) {
        if (l == -1) { l = j; }
        r = j;
      }
    }
    auto hash = GetHash(S.substr(l, r - l + 1) + T.substr(l, r - l + 1));
    if (!mp.count(hash)) { mp[hash] = cnt++, acams.emplace_back(); }
    std::string V = S.substr(0, l) + std::string(1, 'a' + 26) + S.substr(r + 1);
    // std::cerr << "INSERT " << V << ' ' << mp[hash] << '\n';
    acams[mp[hash]].insert(V);
  }

  for (auto &v: acams) { v.build();}

  for (int i = 0; i < Q; i++) {
    std::string S, T;
    std::cin >> S >> T;
    assert(S != T);
    int l = -1, r = -1;
    for (int j = 0; j < (int) S.length(); j++) {
      if (S[j] != T[j]) {
        if (l == -1) { l = j; }
        r = j;
      }
    }
    auto hash = GetHash(S.substr(l, r - l + 1) + T.substr(l, r - l + 1));
    if (!mp.count(hash)) {
      std::cout << 0 << '\n';
      continue;
    }
    std::string V = S.substr(0, l) + std::string(1, 'a' + 26) + S.substr(r + 1);
    // std::cerr << "QUERY " << V << ' ' << mp[hash] << '\n';
    std::cout << acams[mp[hash]].query(V) << '\n';
  }

  return 0;
}

/*
g++ replace.cpp -o replace -O2 -std=c++14 -static &&
ulimit -t 1 &&
ulimit -v 512000 &&
cp replace1.in replace.in && ./replace && diff replace.out replace1.ans &&
cp replace2.in replace.in && ./replace && diff replace.out replace2.ans &&
cp replace3.in replace.in && ./replace && diff replace.out replace3.ans &&
cp replace4.in replace.in && ./replace && diff replace.out replace4.ans &&
cp replace5.in replace.in && ./replace && diff replace.out replace5.ans &&
cp replace6.in replace.in && ./replace && diff replace.out replace6.ans &&
cp replace7.in replace.in && ./replace && diff replace.out replace7.ans &&
echo Accepted!
*/