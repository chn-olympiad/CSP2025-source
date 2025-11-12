#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,t[505],p[505],MOD = 998244353;
bool mark[505];
string s;
bool check(int a[]){
    int day = s.size();
    for(int i = 0;i < day;i++){
        if(s[i] == '0')
            for(int j = i + 2;j <= n;j++)
                a[j]--;
    }
    int employ = 0;
    for(int i = 1;i <= n;i++)
        if(a[i] && s[i - 1] == '1') employ++;
    if(employ >= m) return 1;
    return 0;
}
void dfs(int x){
    if(x > n){
        if(check(t)) cnt = (cnt + 1) % MOD;
        //for(int i = 1;i <= n;i++) cout << t[i] << " ";
        //cout << "\n";
        return;
    }
    for(int i = 1;i <= n;i++){
        if(mark[i]) continue;
        mark[i] = 1;
        t[x] = p[i];
        dfs(x + 1);
        mark[i] = 0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    froepen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++) cin >> p[i];
    int len = s.size(),flag = 1;
    for(int i = 0;i < len;i++){
        if(s[i] != '1'){
            flag = 0;
            break;
        }
    }
    if(flag){
        long long sum = 1;
        for(int i = 1;i <= n;i++)
            sum *= i % MOD;
        cout << sum % MOD;
        return 0;
    }
    dfs(1);
    cout << cnt;
    return 0;
}
