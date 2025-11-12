#include<bits/stdc++.h>
#define pii pair<int,int>
#define pss pair<string,string>
using namespace std;
constexpr int N = 210+10;
int a[N],b[N],c[N];
int f[N][N][N];
int n,ans = 0;
struct node{
    int id,x,to;
    bool operator <(const node &b)const{
        return x > b.x;
    }
};
int cnt[N];
void dfs(int u,int cnt1,int cnt2,int cnt3,int sum){
    if(u == n + 1 && cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2){
        ans = max(ans,sum);
    }
    if(sum <= f[u][cnt1][cnt2]) return;
    if(cnt1 + 1 <= n / 2) dfs(u + 1,cnt1 + 1,cnt2,cnt3,sum + a[u]);
    if(cnt2 + 1 <= n / 2) dfs(u + 1,cnt1,cnt2 + 1,cnt3,sum + b[u]);
    if(cnt3 + 1 <= n / 2) dfs(u + 1,cnt1,cnt2,cnt3 + 1,sum + c[u]);
    f[u][cnt1][cnt2] = sum;
}
bool checkA(){
    bool flag = 0;
    for(int i = 1;i <= n;i++){
        if(b[i] || c[i]) return 0;
    }
    return 1;
}
void solA(){
    sort(a + 1,a + n + 1,greater<int>());
    int sum = 0;
    for(int i = 1;i <= n / 2;i++) sum += a[i];
    cout << sum <<'\n';
}

void solve(){
    memset(f,0,sizeof f);
    ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    if(checkA()){
        solA();
        return;
    }
    if(n > 200){
        memset(f,-1,sizeof f);
        dfs(1,0,0,0,0);
        cout << ans <<'\n';
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= n;j++){
            for(int k = 0;k <= n;k++){
                int l = i - j - k;
                if(l < 0) continue;
                if(j)f[i][j][k] = max(f[i][j][k],f[i - 1][j - 1][k] + a[i]);
                if(k)f[i][j][k] = max(f[i][j][k],f[i - 1][j][k - 1] + b[i]);
                if(l)f[i][j][k] = max(f[i][j][k],f[i - 1][j][k] + c[i]);
            }
        }
    }
    for(int i = 0;i <= n / 2;i++){
        for(int j = 0;j <= n / 2;j++){
            int k = n - i - j;
            if(k > n / 2) continue;
            ans = max(ans,f[n][i][j]);
        }
    }
    //dfs(1,0,0,0,0);
    cout << ans <<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
