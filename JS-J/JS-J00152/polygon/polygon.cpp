#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,ans;
int a[100010];
int main(){
    freopen("r","polygon.in",stdin);
    freopen("w","polygon.out",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>3) cout<<"0";
    if(n==3){
        int maxn=max(a[1],max(a[2],a[3]));
        if(maxn==a[1]){
            if(a[2]+a[3]>2*maxn) ans++;
        }
        if(maxn==a[2]){
            if(a[1]+a[3]>2*maxn) ans++;
        }
        if(maxn==a[3]){
            if(a[1]+a[2]>2*maxn) ans++;
        }
    }
    cout<<ans;
    return 0;
}