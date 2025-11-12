#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
namespace gtx{
    /*
    步骤：
    
    找出主要替换部分
    构建TRIE树
    对于每一个上节点，建立一颗平衡树代表下节点方案数量
    不用平衡树，直接用数组即可
    时间复杂度：O(sigmas log(sigmas) + sigmaq log(signmas))
    空间复杂度：2*sigma
    */
    const int MAXN = 5e6+10;
    int n,q;
    string s1,s2;
    
    int tot_trie;
    struct Trie{
        int son[26];
        int fath;
    }tree[MAXN];
    int roota[MAXN],rootb[MAXN];
    vector<string> v[MAXN];
    int tot_roots;
    unordered_map<string,int> mp;
    unordered_map<long long,int> lb,tmp;
    inline void insert(int x,string y){
        for(char i:y){
            if(!tree[x].son[i-'a']){
                tree[x].son[i-'a'] = ++tot_trie;
                tree[tot_trie].fath = x;
            }
            x = tree[x].son[i-'a'];
        }
    }
    inline void insert(int x,string y,string z){
        for(char i:y){
            if(!tree[x].son[i-'a']){
                tree[x].son[i-'a'] = ++tot_trie;
                tree[tot_trie].fath = x;
            }
            x = tree[x].son[i-'a'];
        }
        v[x].push_back(z);
    }

    inline long long get(int x,int y){
        return 1ll*x*MAXN+y;
    }
    inline void mark(int x,string y){
        for(char i:y){
            x = tree[x].son[i-'a'];
            tmp[x]+=0;
        }
        tmp[x]++;
    }
    inline void go(int x,int z){
        if(tree[x].fath) tmp[x] += tmp[tree[x].fath];
        // cerr << (tmp.find(0)==tmp.end()) << endl;
        for(auto i:tree[x].son){
            if(tmp.find(i)!=tmp.end()){
                go(i,z);
            }
        }
        lb[get(z,x)] += tmp[x];
    }
    inline void went(int x,int y){
        for(auto i:tree[x].son){
            if(i){
                went(i,y);
            }
        }
        // cerr << (tmp.find(0)==tmp.end()) << endl;
        for(auto i:v[x]){
            mark(y,i);
        }
        go(y,x);
        tmp.clear();
    }
    vector<int> foot;
    inline void goes(int x,string y){
        foot.push_back(x);
        for(char i:y){
            if(!tree[x].son[i-'a']) return;
            x = tree[x].son[i-'a'];
            foot.push_back(x);
        }
    }
    inline int find(int x){
        auto L = foot.begin();
        auto R = foot.end()-1;
        if(lb.find(get(x,*R))!=lb.end()) return lb[get(x,*R)];
        int ans = 0;
        while(L<=R){
            auto mid = foot.begin()+(L-foot.begin()+R-foot.begin())/2;
            if(lb.find(get(x,*mid))!=lb.end()){
                L = mid+1;
                ans = lb[get(x,*mid)];
            }else{
                R = mid-1;
            }
        }
        return ans;
    }
    inline int going(int x,string y){
        int ans = find(x);
        for(char i:y){
            if(!tree[x].son[i-'a']) return ans;
            x = tree[x].son[i-'a'];
            ans += find(x);
        }
        return ans;
    }
    signed main(){
        cin >> n >> q;
        for(int i = 1;i<=n;i++){
            cin >> s1 >> s2;
            int l = -1,r = -1;
            int len = s1.size();
            for(int i = 0;i<len;i++){
                if(s1[i]!=s2[i]){
                    if(l==-1) l = i+1;
                    r = i+1;
                }
            }
            if(l==-1) continue;
            string qian = s1.substr(0,l-1);
            reverse(qian.begin(),qian.end());
            string hou = s1.substr(r,len-r);
            if(!mp[s1.substr(l-1,r-l+1)+s2.substr(l-1,r-l+1)]){
                mp[s1.substr(l-1,r-l+1)+s2.substr(l-1,r-l+1)] = ++tot_trie;
                ++tot_trie;
            }
            int id = mp[s1.substr(l-1,r-l+1)+s2.substr(l-1,r-l+1)];
            insert(id,qian,hou);
            insert(id+1,hou);
            // cout << qian << " " << hou << endl;
        }
        for(auto i:mp){
            went(i.second,i.second+1);
        }
        while(q--){
            cin >> s1 >> s2;
            if(s1.size()!=s2.size()){
                cout << 0 << endl;
                continue;
            }
            int l = -1,r = -1;
            int len = s1.size();
            for(int i = 0;i<len;i++){
                if(s1[i]!=s2[i]){
                    if(l==-1) l = i+1;
                    r = i+1;
                }
            }
            string qian = s1.substr(0,l-1);
            reverse(qian.begin(),qian.end());
            string hou = s1.substr(r,len-r);
            if(mp[s1.substr(l-1,r-l+1)+s2.substr(l-1,r-l+1)]==0){
                cout << 0 << endl;
                continue;
            }
            int now = mp[s1.substr(l-1,r-l+1)+s2.substr(l-1,r-l+1)];
            foot.clear();
            goes(now+1,hou);
            if(foot.size()==0) cout << 0 << endl;
            else cout << going(now,qian) << endl;
        }
        return 0;
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int T = 1;
    // gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
/*
g++ replace.cpp -o replace -std=c++14 "-Wl,--stack=1000000000" -Wall -Wextra;if($?){echo "running";./replace}
1.6G<2G
*/