#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pr pair<int,int>
#define mk make_pair
#define lc x<<1
#define rc x<<1|1
#define N 105050
int a[N][3],cnt[3],n,m,T,ans,bel[N];
void sol(){
    cin>>n;
    cnt[0]=cnt[1]=cnt[2]=0;ans=0;
    for(int i=0;i<n;++i)for(int j=0;j<3;++j)cin>>a[i][j];
    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j)if(a[i][j]>=a[i][0]&&a[i][j]>=a[i][1]&&a[i][j]>=a[i][2]){bel[i]=j;break;}
        ++cnt[bel[i]];
        ans+=a[i][bel[i]];
        // cerr<<bel[i]<<' ';
    }
    // cerr<<"\n";
    vector<int>now;
    for(int i=0;i<n;++i)if(cnt[bel[i]]>(n>>1)){
        int x=-0x3f3f3f3f;
        // cerr<<"add "<<i<<"\n";
        for(int j=0;j<3;++j)if(bel[i]!=j)x=max(x,a[i][j]-a[i][bel[i]]);
        now.push_back(x);
    }
    // cerr<<now.size()<<"\n";
    if(!now.empty()){
        sort(now.begin(),now.end());
        for(int i=(n>>1);i<now.size();++i)ans+=now[i];
        // cerr<<now[i]<<" ";
    }
    // cerr<<"\n";
    cout<<ans<<"\n";
}
signed main(){
    clock_t st=clock();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)sol();
    cerr<<fixed<<setprecision(10)<<(double)(clock()-st)/CLOCKS_PER_SEC<<"\n";
}