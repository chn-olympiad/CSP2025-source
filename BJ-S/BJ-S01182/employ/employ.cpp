#include<bits/stdc++.h>
using namespace std;
int a[505];
int solve(int x){
    if(x==1) return 1;
    return x*solve(x-1)%998244353;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int cnt=0;
    for(int i=1;i<=n;i++){
         if(a[i]==0) cnt++;
    }
    cout << solve(n-cnt);
    return 0;
}
