#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e6 + 20;
int n , m , k , tot , fa[N];
struct edge{
    int u , v;
    long long  w;
    bool operator < (const edge &a)const{
        return w > a.w;
    }
}E[N];
int find(int x){
    if(x != fa[x])return fa[x] = find(fa[x]);
    else return x;
}
int read(){
    int k = 0 , f = 1;
    char ch = getchar();
    while(ch < '0' or ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' and ch <= '9'){
        k = k * 10 + ch - '0';
        ch = getchar();
    }
    return k * f;
}
long long a[20][10010];
signed main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    // ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    n = read() , m = read() , k = read();
    for(int i = 1;i <= m;i++){
        E[i].u = read() , E[i].v = read() , E[i].w = read();     
    }
    for(int i = 1;i <= k;i++){
        for(int j = 0;j <= n;j++){
            a[i][j] = read();
        } 
    }
    long long ans = 0x3f3f3f3f3f3f3f;
    long long res = 0;
    for(int i = 0;i <= (1 << k) - 1;i++){
        res = 0;
        tot = m;
        int kk = n;
        for(int j = 1;j <= k;j++){
            if(i & (1 << (j - 1))){
                kk++;
                res += a[j][0];
                for(int b = 1;b <= n;b++){
                    // E[++tot].u = j + n , E[tot].v = b , E[tot].w = a[j][b];
                    E[++tot].u = b , E[tot].v = j + n , E[tot].w = a[j][b];
                }
            }
        }
        // cout << res << endl;
        for(int j = 1;j <= n + k;j++)fa[j] = j; 
        sort(E + 1,E + tot + 1);
        int cnt = 0;
        // cout << kk << endl;
        for(int j = 1;j <= tot;j++){
            int u_ = E[j].u , v_ = E[j].v , w_ = E[j].w;
            //cout << u
            // if(u_ > n and v_ > n)assert(0);
            int uu = find(u_) , vv = find(v_);
            if(uu != vv){
                // cout << u_ << " " << v_ << " " << w_ << " " << uu << " " << vv << endl;
                fa[uu] = vv;
                res += w_;
                cnt++;
            }
            // if(cnt == kk - 1)break;
            if(res > ans)break;
        } 
        ans = min(ans , res);
    }
    cout << ans << '\n';
    return 0;
}