#include<bits/stdc++.h>
using namespace std;
namespace mycode{
    typedef long long ll;
    int n;
    int a[100005][4];
    int c[100005];
    int cnt[4];
    int b[100005];
    int bl;
    ll sum[4];
    ll ans;
    void solve(){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            for(int j=1;j<=3;j++) if(c[i]==0 || a[i][j]>=a[i][c[i]]) c[i]=j;
            cnt[c[i]]++;sum[c[i]]+=a[i][c[i]];
        }
        int mx=0;
        for(int i=1;i<=3;i++) if(cnt[i]>cnt[mx]) mx=i;
        for(int i=1;i<=3;i++) ans+=sum[i];
        if(cnt[mx]>n/2){
            for(int i=1;i<=n;i++) 
                if(c[i]==mx){
                    int nch=0;
                    for(int j=1;j<=3;j++) if(j!=mx && (nch==0 || a[i][j]>=a[i][nch])) nch=j;
                    b[++bl]=a[i][mx]-a[i][nch];
                }
            sort(b+1,b+bl+1);
            for(int i=1;i<=cnt[mx]-(n/2);i++) ans-=b[i];
        }
        printf("%lld\n",ans);
        for(int i=1;i<=3;i++){cnt[i]=0;sum[i]=0;}
        ans=0;bl=0;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--) mycode::solve();
    return 0;
}