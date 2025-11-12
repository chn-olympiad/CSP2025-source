#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int d[N][3];
int g[N];
int n;
void solve(){
    cin>>n;
    ll tot=0;int cnt[3]={};
    for(int i=1;i<=n;i++){
        ll now=0,id=0;
        for(int j=0;j<3;j++){
            cin>>d[i][j];
            if(d[i][j]>=now&&cnt[j]<n/2){
                now=d[i][j];id=j;
            }
        }
        tot+=now;cnt[id]++;
    }
    
    for(int j=0;j<3;j++){
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=d[i][j];
            g[i]=-1;
            for(int k=0;k<3;k++)if(k!=j)g[i]=max(g[i],d[i][k]);
            g[i]-=d[i][j];
        }
        sort(g+1,g+n+1);
        for(int i=n;i>=n/2+1;i--)ans+=g[i];
        tot=max(tot,ans);
    }
    cout<<tot<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}