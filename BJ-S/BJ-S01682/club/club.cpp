#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
constexpr int N=1e5+5;
int T,n,a[N][3],cnt[3];
bool vis[N];
inline void mian(){
    cin>>n;
    rep(i,1,n)rep(j,0,2)cin>>a[i][j];
    int ans=0;
    cnt[0]=cnt[1]=cnt[2]=0;
    memset(vis,0,sizeof(vis));
    vector<array<int,3>> vec;
    rep(i,1,n){
        int mx=-1,to=-1;
        rep(j,0,2)if(a[i][j]>mx)mx=a[i][j],to=j;
        cnt[to]++;
        ans+=mx;
        rep(j,0,2)if(j!=to)vec.pb({mx-a[i][j],to,i});
    }
    sort(vec.begin(),vec.end());
    int over=-1;
    rep(j,0,2)if(cnt[j]>n/2)over=j;
    if(over==-1){
        cout<<ans<<"\n";
        return;
    }
    rep(i,0,(int)vec.size()-1){
        int val=vec[i][0],dep=vec[i][1],id=vec[i][2];
        if(dep!=over||vis[id])continue;
        ans-=val;
        vis[id]=1;
        cnt[over]--;
        if(cnt[over]<=n/2)break;
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)mian();
    return 0;
}