#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],cnt,t;
string s;
long long ans = 1,ans2 = 1,tmp = 1,tmp2 = 1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    t = n;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
        if(c[i] == 0) t--;
    }
    for(char i : s) if(i == '1') cnt++;
    if(cnt == n && t >= m){
        /*for(int i = 1;i <= t;i++){
            ans = (ans * i) % 998244353;
        }
        for(int i = 1;i <= n-t;i++){
            ans2 = (ans2 * i) % 998244353;
        }
        ans = (ans * ans2) % 998244353;*/
        for(int i = 1;i <= m;i++){
            tmp = (tmp * i) % 998244353;
        }
        for(int i = 1;i <= n-m;i++){
            tmp2 = (tmp2 * i) % 998244353;
        }
        tmp = (tmp * tmp2) % 998244353;
        for(int i = 1;i <= t;i++){
            tmp = (tmp * i) % 998244353;
        }
        cout << tmp;
    }else cout << 0;
    /*for(int i = 1;i <= 100;i++){
        ans = (ans * i) % 998244353;
    }
    printf("%lld",ans);*/
    return 0;
}
