#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll t,n,a[maxn][4],k=1,p=1,q=1;
void solve(){
    scanf("%lld",&n);
    ll ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            scanf("%lld",&a[i][j]);
        }
        if(a[i][2]!=0||a[i][3]!=0){
            k=0;
        }
        if(a[i][1]!=0||a[i][2]!=0){
            p=0;
        }
        if(a[i][1]!=0||a[i][3]!=0){
            q=0;
        }
    }
    if(k==1){
        ll b[maxn];
        for(int i=1;i<=n;i++){
            b[i]=a[i][1];
        }
        sort(b+1,b+n+1);
        for(int i=n;i>n/2;i--){
            ans+=b[i];
        }
    }
    else if(p==1){
        ll b[maxn];
        for(int i=1;i<=n;i++){
            b[i]=a[i][3];
        }
        sort(b+1,b+n+1);
        for(int i=n;i>n/2;i--){
            ans+=b[i];
        }
    }
    else if(q==1){
        ll b[maxn];
        for(int i=1;i<=n;i++){
            b[i]=a[i][2];
        }
        sort(b+1,b+n+1);
        for(int i=n;i>n/2;i--){
            ans+=b[i];
        }
    }
    else{
        for(int i=1;i<=n;i+=2){
            int cnt=0;
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(j==k) continue;
                    if(a[i][j]+a[i+1][k]>cnt){
                        cnt=a[i][j]+a[i+1][k];
                    }
                }
            }
            ans+=cnt;
        }
    }
    printf("%lld\n",ans);
    ans=0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        solve();
    }
    return 0;
}
