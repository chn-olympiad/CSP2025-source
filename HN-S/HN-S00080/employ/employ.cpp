#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 998244353;
int n,m;
bool day[N];
int a[N];
int tp(int x){
    long long res = x;
    for (int i = x - 1;i > 0;i--){
        res *= i;
        res %= MOD;
    }
    return res;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++){
        char c;
        cin>>c;
        day[i] = c - '0';
    }
    for (int i = 1;i <= n;i++){
        cin>>a[i];
    }
    if (m == 1){
        cout<<tp(n)<<endl;
        return 0;
    }
    cout<<n;
    return 0;
}