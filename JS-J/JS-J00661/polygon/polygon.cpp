#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md=998244353;
int n,m,a[5005];
ll c[505][505];
ll ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool flag=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)
            flag=0;
    }
    if(n>20&&flag){
        for(int i=0;i<=n;i++){
            c[0][i]=0;
            c[i][0]=1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
        for(int i=3;i<=n;i++){
            ans=(ans+c[n][i])%md;
        }
        cout<<ans;
        return 0;
    }
    for(ll i=1;i<=(1ll<<n)-1;i++){
        int sum=0,mx=-1,cnt=0;
        for(ll j=1;j<=n;j++){
            if((i&(1ll<<(j-1)))==(1ll<<(j-1))){
                sum+=a[j];
                mx=max(mx,a[j]);
                cnt++;
            }
        }
        //cout<<i<<" "<<sum<<" "<<mx<<"\n";
        if(sum>2*mx&&cnt>=3){
            ans++;
            if(ans==md)
                ans=0;
        }
    }
    cout<<ans%md;
    return 0;
}
