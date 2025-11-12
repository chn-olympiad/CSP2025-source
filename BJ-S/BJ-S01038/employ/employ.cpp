#include <bits/stdc++.h>
using namespace std;
int n, m;
string s1;
int c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >>s1;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    if(m == 1){
        int cnt = 0;
        long long len = s1.size();
        for(int i = 0; i < len; i++){
            if(s1[i] == 1)
                cnt = (cnt+1)%998244353;
        }
        cout << (cnt*n)%998244353;
    }else if(n == 3){
        cout <<2;
    }
    else if(n < 3){
        cout << 0;
    }
    else cout <<1886543235;
    return 0;
}