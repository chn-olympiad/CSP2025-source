#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bits/extc++.h>
// #define int long long
using namespace std;
namespace Read{
    inline int read(){
        int f = 0, d = 1; char op;
        while(op = getchar(), !isdigit(op)) if(op == '-') d = - 1;
        while(isdigit(op)) f = (f << 1) + (f << 3) + (op ^ 48), op = getchar();
        return f * d;
    }
} using namespace Read;
namespace YYY{ //注意数组!!!
    const int N = 2e5 + 10, M = 26, K = 5e6 + 10, INF = 0x3f3f3f3f;
    int n, T;
    string s[N][2], t[N][2]; int yjf[N][2];
    string temp1, temp2, temp;
    __gnu_pbds::cc_hash_table<string, int> mp; int idx_mp;
    int ans[N];
    vector<int> v1[N], v2[N];
    struct Node2{int x, y, y2, d, op; }tmp[4 * N]; int idx_tmp;
    struct Node{
        struct Tree{int son[M]; }tree[K]; int Root1, Root2, idx_tree;
        int dfn[K], sa[K], idx_dfn, sz[N];
        int add(int &Root, string &s){
            if(Root == 0) Root = ++ idx_tree;
            int now = Root;
            for(int i = 0; i < (int)s.size(); i ++ ){
                if(tree[now].son[s[i] - 'a'] == 0) tree[now].son[s[i] - 'a'] = ++ idx_tree;
                now = tree[now].son[s[i] - 'a'];
            }
            return now;
        }
        int query(int Root, string &s){
            if(Root == 0) return - 1;
            int now = Root;
            for(int i = 0; i < (int)s.size(); i ++ ){
                now = tree[now].son[s[i] - 'a'];
                if(now == 0) return - 1;
            }
            return now;
        }
        void dfs(int u){
            if(u == 0) return ;
            dfn[ ++ idx_dfn] = u, sa[u] = idx_dfn; sz[u] = 1;
            for(int i = 0; i < M; i ++ ){
                if(tree[u].son[i] != 0){
                    dfs(tree[u].son[i]); sz[u] += sz[tree[u].son[i]];
                }
            }
        }
    } node;
    inline bool cmp(Node2 a, Node2 b){return a.x < b.x || (a.x == b.x && a.op < b.op); }
    struct Node11{
        int b[N], n;
        int lowbit(int x){return x & ( - x); }
        void cl(int x){
            n = x;
            for(int i = 1; i <= n; i ++ ) b[i] = 0;
        }
        void add(int x, int d){
            for(int i = x; i <= n; i += lowbit(i)) b[i] += d;
        }
        int query(int x){
            int ans = 0;
            for(int i = x; i >= 1; i -= lowbit(i)) ans += b[i];
            return ans;
        }
    } node2;
    signed main(){
        n = read(), T = read();
        // cout<<"###\n";
        for(int i = 1; i <= n; i ++ ){
            cin >> temp1 >> temp2;
            if(temp1 == temp2) continue;
            int st = INF, ed = 0;
            for(int j = 0; j < (int)temp1.size(); j ++ ){
                if(temp1[j] != temp2[j]) st = min(st, j), ed = max(ed, j);
            }
            temp = "";
            for(int j = st; j <= ed; j ++ ) temp.push_back(temp1[j]);
            for(int j = st; j <= ed; j ++ ) temp.push_back(temp2[j]);
            for(int j = st - 1; j >= 0; j -- ) s[i][0].push_back(temp1[j]);
            for(int j = ed + 1; j < (int)temp1.size(); j ++ ) s[i][1].push_back(temp1[j]);
            int op; op = mp[temp];
            if(op == 0) mp[temp] = ++ idx_mp, op = idx_mp;
            v1[op].push_back(i);
            // cout<<"### "<<s[i][0]<<' '<<s[i][1]<<'\n';
        }
        for(int i = 1; i <= T; i ++ ){
            cin >> temp1 >> temp2;
            if(temp1.size() != temp2.size()) continue;
            int st = INF, ed = 0;
            for(int j = 0; j < (int)temp1.size(); j ++ ){
                if(temp1[j] != temp2[j]) st = min(st, j), ed = max(ed, j);
            }
            temp = "";
            for(int j = st; j <= ed; j ++ ) temp.push_back(temp1[j]);
            for(int j = st; j <= ed; j ++ ) temp.push_back(temp2[j]);
            for(int j = st - 1; j >= 0; j -- ) t[i][0].push_back(temp1[j]);
            for(int j = ed + 1; j < (int)temp1.size(); j ++ ) t[i][1].push_back(temp1[j]);
            int op; op = mp[temp];
            if(op == 0) mp[temp] = ++ idx_mp, op = idx_mp;
            v2[op].push_back(i);
            // cout<<"??? "<<t[i][0]<<' '<<t[i][1]<<'\n';
        }
        for(int i = 1; i <= idx_mp; i ++ ){
            node.Root1 = node.Root2 = 0;
            for(int j = 0; j < (int)v2[i].size(); j ++ ){
                yjf[v2[i][j]][0] = node.add(node.Root1, t[v2[i][j]][0]);
                yjf[v2[i][j]][1] = node.add(node.Root2, t[v2[i][j]][1]);
                // cout<<v2[i][j]<<' ';
            }
            // cout<<':';
            node.idx_dfn = 0; node.dfs(node.Root1);
            node.idx_dfn = 0; node.dfs(node.Root2);
            idx_tmp = 0;
            for(int j = 0; j < (int)v1[i].size(); j ++ ){
                // cout<<v1[i][j]<<' ';
                int temp1 = node.query(node.Root1, s[v1[i][j]][0]);
                int temp2 = node.query(node.Root2, s[v1[i][j]][1]);
                // cout<<"yjf: "<<temp1<<' '<<temp2<<'\n';
                if(temp1 != - 1 && temp2 != - 1){
                    tmp[ ++ idx_tmp] = {node.sa[temp1], node.sa[temp2], node.sa[temp2] + node.sz[temp2] - 1, 1, 0};
                    tmp[ ++ idx_tmp] = {node.sa[temp1] + node.sz[temp1], node.sa[temp2], node.sa[temp2] + node.sz[temp2] - 1, - 1, 0};
                }
            }
            // cout<<'\n';
            for(int j = 0; j < (int)v2[i].size(); j ++ ){
                tmp[ ++ idx_tmp] = {node.sa[yjf[v2[i][j]][0]], node.sa[yjf[v2[i][j]][1]], 0, 0, v2[i][j]};
            }
            sort(tmp + 1, tmp + 1 + idx_tmp, cmp);
            node2.cl(node.idx_dfn);
            for(int j = 1; j <= idx_tmp; j ++ ){
                if(tmp[j].op != 0) ans[tmp[j].op] = node2.query(tmp[j].y);
                else node2.add(tmp[j].y, tmp[j].d), node2.add(tmp[j].y2 + 1, - tmp[j].d);
            }
        }
        for(int i = 1; i <= T; i ++ ) cout<<ans[i]<<'\n';
        return 0;
    }
}
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    return YYY::main();
}
/*
g++ replace.cpp -o replace -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000 && .\replace.exe < a.in > a.out

g++ replace.cpp -o replace -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000
.\replace.exe < D:\CQ-S00423\replace\replace1.in > a.out && fc a.out D:\CQ-S00423\replace\replace1.ans
.\replace.exe < D:\CQ-S00423\replace\replace2.in > a.out && fc a.out D:\CQ-S00423\replace\replace2.ans
.\replace.exe < D:\CQ-S00423\replace\replace3.in > a.out && fc a.out D:\CQ-S00423\replace\replace3.ans
.\replace.exe < D:\CQ-S00423\replace\replace4.in > a.out && fc a.out D:\CQ-S00423\replace\replace4.ans

*/