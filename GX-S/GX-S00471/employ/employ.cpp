#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
string s;

int main(){
    freopen("employ.in","r", stdin);
    freopen("employ.out", "w", stdout);
    int n,m;
    scanf("%d%d", &n, &m);
    cin>>s;
    int x;
    int num = n;
    for(int i=1;i<=n;i++){
        scanf("%d", &x);
        if(x == 0) num --;
    }
    long long ans = 1;
    if(m > num){
        ans = 0;
        printf("%lld", ans);
        return 0;
    }
    for(int i=num;i>=1;i--){
        ans *= i;
        ans %= mod;
    }
    printf("%lld", ans);

    return 0;
}
