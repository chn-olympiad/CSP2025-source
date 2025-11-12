#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e7,M=998244353;
int n;
int a[5005];
ll sum[N],t,ans,tp;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    sum[1]=a[1]+a[2];t=1;
    for(int i=3;i<=n;i++){
        tp=t;
        for(ll j=1;j<=t;j++){
            if(sum[j]>a[i]){
                ans++;
                ans%=M;
            }
        }
        for(int j=1;j<i;j++){
            sum[++t]=(a[j]+a[i])%M;
        }
        for(ll j=1;j<=tp;j++){
            sum[++t]=(a[i]+sum[j])%M;
        }
    }
    cout<<ans;
    return 0;
}
