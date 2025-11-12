#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int R = 1010;
int a[R];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int num = 0;
    for(int i=0;i <= s.length();i++){
        if(s[i] == '1'){
            num++;
        }
    }

    int nec = 0;
    for(int i = 1;i <= n;i++){
        int a[i];
        cin>>a[i];
        if(a[i] != 0){
            nec++;
        }
    }
    if(m == n){
        if(num == n && nec == n){
            int ans = 1;
            for(int i = 2;i <= n;i++){
                ans *= i;
                ans %= 998244353;
            }
            cout<<ans;
        }else{
            cout<<0;
        }
        return 0;
    }
    ll ans = 1;
    for(int i = 2;i <= nec;i++){
        ans *= i;
        ans %= 998244353;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
