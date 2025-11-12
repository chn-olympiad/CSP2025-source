#include <bits/stdc++.h>
#define N 100002
#define M 5
#define ll long long
using namespace std;
int T,n,lim,a[N][M],cnt[M];
ll ans,b[M][N];
const ll inf=1e12;
void init(){
    memset(b,0,sizeof b);
    memset(cnt,0,sizeof cnt);
    ans=0;
}
void solve(){
    cin>>n;lim=n/2;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
            cnt[1]++;
            ans+=a[i][1];
            b[1][i]=a[i][1]-max(a[i][2],a[i][3]);
            b[2][i]=b[3][i]=inf;
        }else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
            cnt[2]++;
            ans+=a[i][2];
            b[2][i]=a[i][2]-max(a[i][1],a[i][3]);
            b[1][i]=b[3][i]=inf;
        }else{
            cnt[3]++;
            ans+=a[i][3];
            b[3][i]=a[i][3]-max(a[i][1],a[i][2]);
            b[1][i]=b[2][i]=inf;
        }
    }
    if(cnt[1]>lim){
        sort(b[1]+1,b[1]+n+1);
        for(int i=1;i<=n;i++){
            cnt[1]--;
            ans-=b[1][i];
            if(cnt[1]<=lim)  break;
        }
    }else if(cnt[2]>lim){
        sort(b[2]+1,b[2]+n+1);
        for(int i=1;i<=n;i++){
            cnt[2]--;
            ans-=b[2][i];
            if(cnt[2]<=lim)  break;
        }
    }else if(cnt[3]>lim){
        sort(b[3]+1,b[3]+n+1);
        for(int i=1;i<=n;i++){
            cnt[3]--;
            ans-=b[3][i];
            if(cnt[3]<=lim)  break;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        init();
        solve();
    }
    return 0;
}