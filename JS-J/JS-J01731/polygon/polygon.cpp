#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int ans,cur;
int a[5005],sa[5005],cnt[5005];
void work(){
    for()
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            if(sa[j]-sa[i-1]>a[j]*2) ans=(ans+1)%MOD;
            else break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
