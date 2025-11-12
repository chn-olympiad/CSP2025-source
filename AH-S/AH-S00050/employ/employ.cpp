#include<bits/stdc++.h>

using namespace std;

int n, m, c[505], cnt1, cnt0;
string s;
bool flag=false;
long long ans;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i=1; i<=n; i++){
        cin >> c[i];
        if(c[i] == 0){
            cnt0 ++;
        }
    }
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            flag = true;
        }else{
            cnt1 ++;
        }
    }
    if(!flag){//A
        int f = false;
        int cnt = 0, minn = 0x3f3f3f3f;
        for(int i=1; i<=n; i++){
            if(c[i] == 0){
                f = true;
                cnt++;
            }else{
                minn = min(minn, c[i]);
            }
        }
        if(cnt < minn) f = false;
        if(!f){
            ans = 1;
            for(int i=1; i<=n; i++){
                ans *= i;
                ans = ans%998244353;
            }
        }else{

        }
    }else{
        if(cnt1 == 18){
            if(m > 18){
                ans = 0;
            }
        }else if(m > cnt1){
            ans = 0;
        }else if(n - cnt0 < m){
            ans = 0;
        }
    }
    cout << ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
