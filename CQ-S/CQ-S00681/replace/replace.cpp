#include<bits/stdc++.h>
#include<bits/extc++.h>
using ll = long long; using ull = unsigned long long;
#define ld std::cin
#define jyt std::cout
#define cmd std::cerr
#define REQ(i, l, r) for (int i = l; i <  r; ++i)
#define REP(i, l, r) for (int i = l; i <= r; ++i)
#define PER(i, l, r) for (int i = l; i >= r; --i)
namespace JoKing { // JoKing 2h15min Accepted
   const int N = 2e5 + 7, M = 6e6 + 7;
   const int inf = 1e9 + 7;
   const ull Base = 1145141;
   int n, q; ull base[M]; std::string cache[N];
   struct Czxd {
      int len; ull h1, h2;
      inline bool operator < (const Czxd &p) const {
         if (len ^ p.len) return len < p.len;
         if (h1 ^ p.h1) return h1 < p.h1;
         return h2 < p.h2;
      }
   };
   std::map<Czxd, int> lxl; 
   struct Trie {int son[26], czx;};
   struct TrieIN {
      Trie tr[M]; int Trc;
      inline void extend(int &Rt, std::string &S) {
         if (!Rt) Rt = ++Trc;
         else tr[++Trc] = tr[Rt], Rt = Trc;
         int x = Rt;
         REQ(i, 0, (int)S.size()) {
            if (!tr[x].son[S[i] - 'a']) tr[x].son[S[i] - 'a'] = ++Trc;
            else tr[++Trc] = tr[tr[x].son[S[i] - 'a']], tr[x].son[S[i] - 'a'] = Trc;
            x = tr[x].son[S[i] - 'a'];
         }
         ++tr[x].czx;
      }
      inline int solve(int &Rt, std::string &S) {
         int x = Rt, Res = tr[x].czx;
         REQ(i, 0, (int)S.size()) {
            if (!tr[x].son[S[i] - 'a']) break;
            x = tr[x].son[S[i] - 'a'], Res += tr[x].czx;
         }
         return Res;
      }
   } TIN;
   int head[M], val[M], nxt[M], total = 0;
   inline void add(int Rt, int x) {
      ++total;
      val[total] = x;
      nxt[total] = head[Rt];
      head[Rt] = total; 
   }
   struct TrieOUT {
      Trie tr[M]; int Trc;
      inline void extend(int &Rt, int idx, std::string &S) {
         int x = Rt;
         REQ(i, 0, (int)S.size()) {
            if (!tr[x].son[S[i] - 'a']) tr[x].son[S[i] - 'a'] = ++Trc;
            x = tr[x].son[S[i] - 'a'];
         }
         add(x, idx);
      }
      inline void build(int x) {
         for (int i = head[x]; i; i = nxt[i]) TIN.extend(tr[x].czx, cache[val[i]]);
         REQ(i, 0, 26) if (tr[x].son[i]) tr[tr[x].son[i]].czx = tr[x].czx, build(tr[x].son[i]);
      }
      inline int solve(int &Rt, std::string &SL, std::string &SR) {
         int x = Rt;
         REQ(i, 0, (int)SL.size()) {
            if (!tr[x].son[SL[i] - 'a']) break;
            x = tr[x].son[SL[i] - 'a'];
         }
         return TIN.solve(tr[x].czx, SR);
      }
   } TOUT;
   signed main() {
      ld >> n >> q, base[0] = 1;
      REP(i, 1, 5000000) base[i] = base[i - 1] * Base;
      REP(i, 1, n) {
         int len = 0, L = 0, R = 0; 
         ull keyS = 0, keyT = 0; 
         std::string S = "", T = ""; 
         ld >> S >> T, len = (int)S.size();
         if (S == T) continue;
         REP(j, 1, len) if (S[j - 1] != T[j - 1]) {L = j; break;}
         PER(j, len, 1) if (S[j - 1] != T[j - 1]) {R = j; break;}
         int KEY = R - L + 1;
         REP(j, 1, KEY) {
            keyS += base[j - 1] * S[L + j - 2];
            keyT += base[j - 1] * T[L + j - 2];
         }
         keyS *= base[5000000 - KEY];
         keyT *= base[5000000 - KEY];
         int& now = lxl[(Czxd) {KEY, keyS, keyT}];
         if (!now) now = ++(TOUT.Trc);
         std::string SL = "", SR = "";
         PER(j, L - 1, 1) SL += S[j - 1];
         REP(j, R + 1, len) SR += S[j - 1];
         TOUT.extend(now, i, SL), cache[i] = SR;
      }
      for (auto node : lxl) TOUT.build(node.second);
      REP(Case, 1, q) {
         int len = 0, L = 0, R = 0; 
         ull keyS = 0, keyT = 0; 
         std::string S = "", T = "";
         ld >> S >> T, len = (int)S.size();
         if (S.size() != T.size()) {jyt << 0 << '\n'; continue;}
         REP(j, 1, len) if (S[j - 1] != T[j - 1]) {L = j; break;}
         PER(j, len, 1) if (S[j - 1] != T[j - 1]) {R = j; break;}
         int KEY = R - L + 1;
         REP(j, 1, KEY) {
            keyS += base[j - 1] * S[L + j - 2];
            keyT += base[j - 1] * T[L + j - 2];
         }
         keyS *= base[5000000 - KEY];
         keyT *= base[5000000 - KEY];
         int& now = lxl[(Czxd) {KEY, keyS, keyT}];
         if (!now) {jyt << 0 << '\n'; continue;}
         std::string SL = "", SR = "";
         PER(j, L - 1, 1) SL += S[j - 1];
         REP(j, R + 1, len) SR += S[j - 1];
         jyt << TOUT.solve(now, SL, SR) << '\n';
      }
      return 0;
   }
}
signed main() {
#ifdef WYY
   freopen("replace4.in", "r", stdin);
   freopen("file/code.out", "w", stdout);
#else
   freopen("replace.in", "r", stdin);
   freopen("replace.out", "w", stdout);
#endif
   std::ios::sync_with_stdio(false), ld.tie(0), jyt.tie(0);
   JoKing::main();
#ifdef WYY
   // while(true);
#endif
   return 0;
}
/*
aaaaa
aabaa
每一种二元组替换的位置唯一。
考虑不相同位置，这是显然的。
相同位置 hash 值必须相同。
不同串长度仅仅有 1600 种。
考虑建立 Trie 树。
这是一个 Trie 树上面搞可持久化 Trie 树。
可以快速合并祖先链的 Trie 树。
空间复杂度为 O(\sigma|s| \times 26)。
因为每一次继承至多新产生 O(|S|) 个结点。
感觉我的做法很沙比。
*/