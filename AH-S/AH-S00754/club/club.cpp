#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=100005;
ll T,n,a[maxn][5],f[5][maxn],sum[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(sum,0,sizeof(sum));
        ll ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            ll loc=0,d=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>=a[i][loc])
                    loc=j;
                }
            sum[loc]++;
            ans+=a[i][loc];
            for(int j=1;j<=3;j++){
                if(loc==j) continue;
                if(a[i][j]>a[i][d])
                    d=j;
            }
            f[loc][sum[loc]]=a[i][loc]-a[i][d];
        }
        ll p=0,tot=0;
        for(int i=1;i<=3;i++)
            if(sum[i]>sum[p])
                p=i;
        sort(f[p]+1,f[p]+sum[p]+1);
        while(sum[p]>n/2){
            tot++;
            sum[p]--;
            ans-=f[p][tot];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
// 15:13
