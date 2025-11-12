//#define DBG

#ifdef DBG
#include <iostream>
#else
#include <fstream>

namespace std {
    ifstream cin("road.in");
    ofstream cout("road.out");
}
#endif
#include <algorithm>
#include <vector>
#define let const auto
#define ll long long int

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge y) const {
        return w < y.w;
    }
    void reinit(int nu, int nv, ll nw) {u = nu, v = nv, w = nw;}
} edgs[10000011];

int n, m, k; // k <= 10

ll sumw[16384];
int patri[16384];
bool banned[16384];
// int fixable[16384];

// struct fEdg {
//     int v;
//     ll w;
//     fEdg(int nv, ll nw) : v(nv), w(nw) {}
// };

// std::vector<fEdg> fed[16];
// int fixes[16];
int fp[16];
int added;
inline void init() {
    for(int i = 1; i <= n + k; i++) {
        patri[i] = i;
    }
}
inline void mrg(int x, int y) {
    patri[x] = y;
}
int pat(int x) {
    return (patri[x] == x) ? x : (patri[x] = pat(patri[x]));
}

inline ll tril() {
    init();
    int cnt = 0;
    ll ret = 0;
    for(int i = 0; i < m; i++) {
        if(cnt >= n-1+added) break;
        if(pat(edgs[i].u) != pat(edgs[i].v) && !banned[edgs[i].u] && !banned[edgs[i].v]) {
            mrg(edgs[i].u, edgs[i].v);
            ++cnt;
            ret += edgs[i].w;
            sumw[edgs[i].u] += edgs[i].w;
            sumw[edgs[i].v] += edgs[i].w;
            // if(fixable[edgs[i].u]) {
            //     fed[fixable[edgs[i].u]].push_back(fEdg(edgs[i].v, edgs[i].w));
            // }
            // if(fixable[edgs[i].v]) {
            //     fed[fixable[edgs[i].v]].push_back(fEdg(edgs[i].u, edgs[i].w));
            // }
        }
    }
    return ret;
}

// ll dfs(int pos) {
//     if(pos == k) return 0;
//     ll ret = dfs(pos+1);
//     if(sumw[fixes[pos]] > fp[pos]) {
//         for(auto &t : fed[pos]) {
//             sumw[t.v] -= t.w;
//         }
//         let save = fp[pos] - sumw[fixes[pos]];
//         let res = dfs(pos+1);
//         for(auto &t : fed[pos]) {
//             sumw[t.v] += t.w;
//         }
//         if(save + ref > ret) {
//             ret = save + ref;
//         }
//     }
//     return ret;
// }

struct fff {
    ll pp;
    int idx;
    bool operator<(const fff y) const {
        return pp > y.pp;
    }
} fffs[16];

int main() {
    std::cin >> n >> m >> k;
    int u, v;
    ll  w;
    for(int i = 0; i < m; i++) {
        std::cin >> u >> v >> w;
        edgs[i].reinit(u, v, w);
    }
    if(k == 0) {
        std::sort(edgs, edgs+m);
        std::cout << tril() << '\n';
        return 0;
    }
    added = k;
    // k_idx = n+i
    ll sumfp = 0;
    for(int i = 1; i <= k; i++) {
        std::cin >> fp[i];
        fffs[i].pp = fp[i];
        fffs[i].idx = i;
        sumfp += fp[i];
        for(int j = 1; j <= n; j++) {
            std::cin >> w;
            edgs[m++].reinit(n+i, j, w);
            #ifdef DBG
            std::cerr << "Add: " << n+i << "->" << j << " : " << w << "\n";
            #endif
        }
    }
    std::sort(edgs, edgs+m);
    std::sort(fffs+1, fffs+k+1);
    ll curm = tril() + sumfp;
    #ifdef DBG
    std::cerr << "Full: " << curm << '\n';
    #endif
    for(int idd = 1; idd <= k; idd++) {
        let i = fffs[idd].idx;
        banned[n+i] = true;
        added--;
        sumfp -= fp[i];
        let res = tril() + sumfp;
        if(curm + fp[i] > res) {
            curm = res;
        } else {
            banned[n+i] = false;
            added++;
        }
        #ifdef DBG
        std::cerr << "With?" << n+i << " ans=" << curm << ", res=" << res << '\n';
        #endif
    }
    std::cout << curm << '\n';
    return 0;
}