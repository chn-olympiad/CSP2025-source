#include<bits/stdc++.h>

#define int long long
#define rep(i,l,r) for(int i = l;i <= r;i ++)
#define dep(i,l,r) for(int i = l;i >= r;i --)
#define mem(x,y) memset(x,y,sizeof(x))

using namespace std;

int read(){
    int s = 0,w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

int n,m;
char s[100010];
int a[1000010];
int f[110][110][110];
int cnt[1000010];
int tot[1000010];
int fac[1000010],ifac[1000010];
int pre[1000010];
bool bk[100010];
int b[1000010];
int ans;
const int mod = 998244353;

void Add(int &x,int y){x = (x + y) % mod;}
void Mul(int &x,int y){x = (x * y) % mod;}

int poww(int x,int y){
    int s = 1;
    for(;y;x = (x * x) % mod,y /= 2)if(y & 1)s = s * x % mod;
    return s;
}

void init(){
    n = 100000;
    fac[0] = 1,ifac[0] = 1;
    rep(i,1,n)fac[i] = (fac[i - 1] * i) % mod;
    ifac[n] = poww(fac[n],mod - 2);
    dep(i,n - 1,1)ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline int C(int x,int y){return fac[x] * ifac[y] % mod * ifac[x - y] % mod;}

bool check(){
    int res = 0;
    int les = 0;
    rep(i,1,n){
        if(s[i] == '0')les ++;
        else {
            if(b[i] <= les)les ++;
            else res ++;
        }
    }
    return res >= m;
}

void dfs(int dep){
    if(dep > n){
        if(check())ans ++;
        return ;
    }
    rep(i,1,n){
        if(bk[i])continue;
        b[dep] = a[i];
        bk[i] = 1;
        dfs(dep + 1);
        bk[i] = 0;
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    init();
    cin>>n>>m;
    scanf("%s",s + 1);
    rep(i,1,n)pre[i] = pre[i - 1] + (s[i] == '1');
    rep(i,1,n)a[i] = read(),cnt[a[i]] ++,tot[a[i]] ++;
    dfs(1);
    cout<<ans;
//     rep(i,1,n)cnt[i] += cnt[i - 1];
//     f[0][0][0] = 1;
//     rep(i,0,n - 1){
//         rep(j,0,i){
//             rep(k,0,i){
//                 //i+1是一个即将录取的,这说明这个人>i-j,需要下一位是1
//                 if(s[i + 1] == '1')Add(f[i + 1][j + 1][k],f[i][j][k]);
//                 //i+1被放弃了
//                 //i+1是0
//                 if(s[i + 1] == '0'){
//                     //需要枚举i-j+1放几个在录取的位置，总共有i+1-k个位置
//                     rep(t,0,min(cnt[i - j + 1],j - k))Add(f[i + 1][j][k + t],f[i][j][k] * C(tot[i - j + 1],t) % mod * fac[t] % mod);
//                 }
//                 //i+1是1,说明这个人<=输场(i - j)
//                 if(s[i + 1] == '1'){
//                     rep(t,0,min(cnt[i - j + 1],j - k))
//                 Add(f[i + 1][j][k + t + 1],f[i][j][k] * (cnt[i - j] - k - pre[i]) % mod * C(tot[i - j + 1],t) % mod * fac[t] % mod);
               
//                 }
//                 // Add(f[i + 1][j][k + t],f[i][j][k] % mod * C(tot[i - j + 1],t) % mod * fac[t] % mod);
//                 //i+1是
//                 //i+1是0,并且本来就录不了
//             }
//         }
//     }
//     int ans = 0;
//     rep(j,m,n)rep(k,0,min(cnt[n - j],j))Add(ans,f[n][j][k] * C(n - cnt[n - j],j - k) % mod * fac[n - j] % mod);
//    // cout<<"f = "<<f[2][1][1]<<endl;
//     cout<<ans;
}
