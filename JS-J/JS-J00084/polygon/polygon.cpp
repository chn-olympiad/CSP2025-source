#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
long long ans;
int a[5010];
void dg(int x,int sum){
    if(x==n+1){
        return ;
    }
    if(sum>a[x]){
        ans++;
        ans%=mod;
    }
    dg(x+1,sum+a[x]);
    dg(x+1,sum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    dg(1,0);
    cout << ans;    
    fclose(stdin);
    fclose(stdout);
    return 0;
}