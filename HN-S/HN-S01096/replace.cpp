#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int INF = 1e9 + 1;
template<typename T> inline void chkmax(T& x,T y){ (x < y) && (x = y); }
template<typename T> inline void chkmin(T& x,T y){ (x > y) && (x = y); }
const int N = 200005;
const int M = 5000005;
int n,q,L1,L2;
string s[N][2],t[N][2];
vector<vector<ull>> hs[2],ht[2];
ull base = 52237,pw[M];
inline ull get(int l,int r,vector<ull> h){
    return h[r] - h[l-1] * pw[r-l+1];
}
int L[M],R[M];
namespace sub1 {
    inline void main(){
        for(int i = 1;i <= q;i++){
            if(t[i][0].size() != t[i][1].size()){ cout << "0\n"; continue; }
            int len = t[i][0].size() - 1;
            L[i] = len + 1,R[i] = 0; 
            for(int j = 1;j <= len;j++)
                if(t[i][0][j] != t[i][1][j]){ L[i] = j; break; }
            for(int j = len;j;j--)
                if(t[i][0][j] != t[i][1][j]){ R[i] = j; break; }
            long long ans = 0;
            for(int j = 1;j <= n;j++){
                int l = s[j][0].size() - 1;
                ull H0 = hs[0][j][l],H1 = hs[1][j][l];
                for(int k = max(1,R[i] - l + 1);k <= min(L[i],len) && k + l - 1 <= len;k++){
                    if(get(k,k + l - 1,ht[0][i]) != H0) continue;
                    if(get(k,k + l - 1,ht[1][i]) != H1) continue;
                    ans ++;
                }
            }
            cout << ans << "\n";
        }
        return ;
    }
}
namespace sub2 {
    inline void main(){
        for(int i = 1;i <= q;i++){
            if(t[i][0].size() != t[i][1].size()){ cout << "0\n"; continue; }
            int len = t[i][0].size() - 1;
            L[i] = len + 1,R[i] = 0; 
            for(int j = 1;j <= len;j++)
                if(t[i][0][j] != t[i][1][j]){ L[i] = j; break; }
            for(int j = len;j;j--)
                if(t[i][0][j] != t[i][1][j]){ R[i] = j; break; }
            long long ans = 0;
            for(int j = 1;j <= n;j++){
                int l = s[j][0].size() - 1;
                ull H0 = hs[0][j][l],H1 = hs[1][j][l];
                for(int k = 1;k + (R[i] - L[i] + 1) - 1 <= l;k++){
                    int a = L[i] - k + 1,b = R[i] + l - (k + R[i] - L[i]);
                    if(a < 1 || b > len) continue;
                    if(get(a,b,ht[0][i]) != H0 || get(a,b,ht[1][i]) != H1) continue;
                    ans ++;
                }
            }
            cout << ans << "\n";
        }
        return ;
    }
}
namespace sub3 {
    struct node {
        int d,ll,rl,id;
    } a[N],b[N];
    inline bool cmp(node x,node y){
        if(x.d ^ y.d) return x.d < y.d;
        return x.ll < y.ll;
    }
    struct BIT {
        int tr[M];
        #define lowbit(x) (x & (-x))
        inline void add(int x,int val){
            x ++;
            for(int i = x;i <= max(L1,L2);i += lowbit(i)) tr[i] += val;
        }
        inline int ask(int x){
            x ++;
            int ans = 0;
            for(int i = x;i;i -= lowbit(i)) ans += tr[i];
            return ans;
        }
    } T;
    int ans[N];
    inline void main(){
        for(int i = 1;i <= n;i++){
            int p[2];
            int l = s[i][0].size() - 1;
            for(int j = 0;j < 2;j++){
                for(int k = 1;k <= l;k++) 
                    if(s[i][j][k] == 'b'){ p[j] = k; break;}
            }
            a[i] = {p[1] - p[0],min(p[1] - 1,p[0] - 1),min(l - p[1],l - p[0]),0};
        }
        int _q = 0;
        for(int i = 1;i <= q;i++){
            int p[2];
            int l = t[i][0].size() - 1;
            for(int j = 0;j < 2;j++){
                for(int k = 1;k <= l;k++) 
                    if(t[i][j][k] == 'b'){ p[j] = k; break;}
            }
            if(t[i][0].size() != t[i][1].size()) ans[i] = 0;
            else b[++ _q] = {p[1] - p[0],min(p[1] - 1,p[0] - 1),min(l - p[1],l - p[0]),i};
        }
        sort(a + 1,a + n + 1,cmp);
        swap(_q,q);
        sort(b + 1,b + q + 1,cmp);
        for(int d = -max(L1,L2),li = 1,lj = 1;d <= max(L1,L2);d++){
            int ri = li-1,rj = lj-1;
            while(ri < n && a[ri+1].d == d) ri ++;
            while(rj < q && b[rj+1].d == d) rj ++;
            if(rj < lj){ li = ri + 1,lj = rj + 1; continue; }
            if(ri < li){
                for(int k = lj;k <= rj;k++) ans[b[k].id] = 0;
                li = ri + 1,lj = rj + 1;
                continue;
            }
            int i = li - 1;
            for(int j = lj;j <= rj;j++){
                while(i < ri && a[i + 1].ll <= b[j].ll) i++,T.add(a[i].rl,1);
                ans[b[j].id] = T.ask(b[j].rl);
            }
            while(i >= li) T.add(a[i].rl,-1),i--;
            li = ri + 1,lj = rj + 1;
        }
        for(int i = 1;i <= _q;i++) cout << ans[i] << "\n";
        return ;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 0;i < 2;i++) 
        hs[i].resize(n + 5),ht[i].resize(q + 5);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 2;j++){
            cin >> s[i][j],L1 += s[i][j].size(),s[i][j] = ' ' + s[i][j];
            hs[j][i].resize(s[i][j].size() + 5);
            for(int k = 1;k < s[i][j].size();k++)
                hs[j][i][k] = hs[j][i][k-1] * base + s[i][j][k];
        }
    }
    for(int i = 1;i <= q;i++){
        for(int j = 0;j < 2;j++){
            cin >> t[i][j],L2 += t[i][j].size(),t[i][j] = ' ' + t[i][j];
            ht[j][i].resize(t[i][j].size() + 5);
            for(int k = 1;k < t[i][j].size();k++)
                ht[j][i][k] = ht[j][i][k-1] * base + t[i][j][k];
        }
    }
    pw[0] = 1;
    for(int i = 1;i <= max(L1,L2);i++) pw[i] = pw[i-1] * base;
    if(1ll * n * L2 <= 200000000){
        sub1::main(); return 0;
    }
    if(1ll * q * L1 <= 200000000){
        sub2::main(); return 0;
    } 
    bool fl = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 2;j++){
            bool o = 0;
            for(int k = 1;k < s[i][j].size();k++){
                if(s[i][j][k] > 'b') fl = 0;
                if(s[i][j][k] == 'b'){ if(o) fl = 0; o = 1;}
            }
            if(!o) fl = 0; 
        }
    }
    for(int i = 1;i <= q;i++){
        for(int j = 0;j < 2;j++){
            bool o = 0;
            for(int k = 1;k < t[i][j].size();k++){
                if(t[i][j][k] > 'b') fl = 0;
                if(t[i][j][k] == 'b'){ if(o) fl = 0; o = 1;}
            }
            if(!o) fl = 0;
        }
    }
    if(!fl){
        for(int i = 1;i <= q;i++) cout << "0\n";
        return 0;
    }
    sub3::main();
    return 0;
}
/*
g++ replace.cpp -o replace -std=c++14 -O2 -static
time ./replace
*/
/*
4 1
aabaa baaaa
aab baa
aaaab aabaa
aabaaa baaaaa
aaabaa abaaaa 
*/