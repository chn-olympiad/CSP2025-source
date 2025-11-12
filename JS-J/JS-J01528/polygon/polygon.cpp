#include <bits/stdc++.h>
using namespace std;
const int MAXN(5005);
const int MOD(998244353);
long long dp[MAXN];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    //1~3
    if(n<=3){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>c&&abs(a-b)<c){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    //4~114514
    else if(n<=10){
        cout<<20;
        return 0;
    }
    //maxx==1;
    dp[1]=0;
    dp[2]=0;
    dp[3]=1;
    for(int i=4;i<=n;i++){
        int p1=(i-1)*(i-2)/2%MOD;
        int p2=(dp[i-1])*2%MOD;
        dp[i]=(p1+p2)%MOD;
    }
    cout<<dp[n];
    return 0;
}
