#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

long long ans;
int n,m;
int can,e = -1;
char s[510];
int person[510];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> s[i];
        cout << n << " " << i << endl;
    }
    for(int i = 1;i <= n;i++){
        cin >> person[i];
        cout << "23820839208423asdjklanudas";
    }
    for(int i = 0;i < n;i++){
        if(s[i] == '1'){
            can++;
        }
        if(s[i] == '0' && e == -1){
            e = i + 1;
        }
    }
    if(can < m){
        cout << "0";
        return 0;
    }
    if(e - 1 >= m || e == -1){
        ans = 1;
        for(int i = n;i >= 1;i--){
            ans = ans * i % MOD;
        }
        cout << ans;
        return 0;
    }
    sort(person + 1,person + 1 + n);
    if(can == m){
        int use = 0;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '1'){
                int a = 0;
                for(int j = 1;j <= n;i++){
                    if(person[j] >= i){
                        a++;
                    }
                }
                ans = ans * (a - use) % MOD;
                use++;
            }
        }
        cout << ans;
    }

    return 0;
}
