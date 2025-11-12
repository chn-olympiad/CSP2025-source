#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+3,INF=1e18;
int T,n,a[N][4];
vector<int> v[4];
void Solve(){
    int ans=0;
    cin>>n;
    for(int i=1;i<=3;i++) v[i].clear();
    for(int i=1;i<=n;i++){
        int mx=-INF,mn=INF,sum=0;
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            mx=max(mx,a[i][j]),mn=min(mn,a[i][j]);
            sum+=a[i][j];
        }
        bool flag=0;
        for(int j=1;flag==0&&j<=3;j++){
            if(a[i][j]==mx){
                ans+=mx;
                v[j].push_back({a[i][j]-(sum-mx-mn)});
                flag=1;
                break;
            }
        }
    }
    for(int i=1;i<=3;i++){
        if(v[i].size()>n/2){
            sort(v[i].begin(),v[i].end());
            int cnt=0;
            while(cnt<v[i].size()-n/2){
                cnt++;
                ans-=v[i][cnt-1];
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    cin>>T;
    while(T--) Solve();
    return 0;
}