#include<bits/stdc++.h>
using namespace std;
long long n, m, ans;
char s[510];
long long c[510], mod = 998244353;
int f[100];
bool aa, v[100];
int cnt0;
void shit(int x){
    if(x > n){
        //cout<<"!!!!!!!!!!!"<<endl;
        int q = 0, e = 0;
        for(int i = 1; i <= n; i++){
            if(q >= c[f[i]]){
                q++;
                continue;
            }
            if(s[i] == '0'){
                q++;
                continue;
            }
            e++;
        }
        if(e >= m){
            ans++;
        }
        return;
    }

    for(int i = 1; i <= n; i++){

        if(v[i]) continue;
        v[i] = true;
        f[x] = i;
        shit(x + 1);
        v[i] = false;
    }

}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    aa = true;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
        if(s[i] == '0') aa = false;
    }
    for(int i = 1; i <= n; i++){
        cin>>c[i];
        if(c[i] == 0) cnt0++;
    }
    if(n <= 100){
        for(int i = 1; i <= n; i++) v[i] = false;
        shit(1);
        cout<<ans;
        return 0;
    }
    /*if(aa){
        ans = 1;
        for(int i = 1; i <= n - 1; i++){
            ans = ans * i % mod;
        }
        cout<<ans;
        return 0;
    }*/
}
