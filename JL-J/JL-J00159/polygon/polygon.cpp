#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,cnt=0;
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n&&j!=i;j++){
            for(int k=1;k<=n&&k!=i&&k!=j;k++){
                int maxn=max(a[i],a[j]);
                maxn=max(maxn,a[k]);
                if(a[i]+a[j]+a[k]>maxn*2){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt%MOD;
    return 0;
}
