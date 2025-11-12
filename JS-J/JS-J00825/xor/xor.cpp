#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,k,a[N],ans = 0,used[N],dp[N],wz = 1;
bool find_(int x,int y){
    int num = a[x];
    if(num == k){
        return 1;
    }
    for(int i = x - 1;i >= y;i --){
        num = (num ^ a[i]);
        if(num == k){
            return 1;
        }
    }
    if(num == k){
        return 1;
    }
    return 0;
}

signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i ++){
        if(find_(i,wz) == 1){
            dp[i] = dp[i - 1] + 1;
            wz = i + 1;
        }
        else{
            dp[i] = dp[i - 1];
        }
    }
    cout<<dp[n];
    return 0;
}
