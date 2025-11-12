#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],ans;
void s(int h,int sum,int m,int z){
    if(h>z){
        if(sum>m*2){
            ans++;
        }
        return;
    }
    for(int i=h+1;i<=n;i++){
        s(h+1,sum+a[i],max(m,a[i]),z);
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        s(0,0,LONG_LONG_MIN,i);
    }
    cout<<ans%998244353;
    return 0;
}
