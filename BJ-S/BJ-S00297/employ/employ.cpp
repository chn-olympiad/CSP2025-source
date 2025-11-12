#include <iostream>
using namespace std;

const int N = 505;

int n,m;
string s;
int a[N],cnt[N],sum1,id[N];
bool vis[N];
int p[N];

int ans;

void dfs(int step){
    if(step == n + 1){
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(s[i - 1] == '0'){
                cnt++;
                continue;
            }
            if(cnt >= a[p[i]]){
                cnt++;
                continue;
            }
        }
        if(n - cnt >= m) ans++;
        return;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i]) continue;
        p[step] = i;
        vis[i] = 1;
        dfs(step + 1);
        vis[i] = 0;
    }
}

int tot;

const int mod = 998244353;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 0;i < s.size();i++){
        if(s[i] == '1') id[++tot] = i;
    }
    if(n <= 10){
        dfs(1);
        cout << ans << endl;
        return 0;
    }
    
    if(n == m){
        if(cnt[0] || tot != n) cout << 0 << endl;
        else{
            long long ji = 1;
            for(int i = 1;i <= n;i++){
                ji = ji * i % mod;
            }
            cout << ji << endl;
        }
    }
}