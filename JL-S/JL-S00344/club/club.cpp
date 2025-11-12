#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
constexpr int N=1e5+10,inf=1e9;
int n,a[N][4],to[N],cnt[5],vis[N][3];
long long WORK(){
    long long res=0;
    cnt[1]=cnt[2]=cnt[3]=0;
    for(int i=1;i<=n;i++){
        int x=(a[i][1]>a[i][2]?1:2);
        x=(a[i][x]>a[i][3]?x:3);
        cnt[x]++,res+=a[i][x];
    }
    if(max({cnt[1],cnt[2],cnt[3]})<n/2) return res;
    return 0;
}
tuple<int,int,int> c[N*2];
long long work(int x){
    long long res=0;
    int p=0;
    for(int i=1;i<=n;i++){
        to[i]=x,res+=a[i][x];
        for(int j=1;j<=3;j++) if(j!=x) c[++p]={a[i][j]-a[i][x],i,j};
    }
    sort(c+1,c+p+1);
    for(int i=1;i<=n/2;i++){
        int w,j,t;tie(w,j,t)=c[p--];
        while(to[j]!=x)tie(w,j,t)=c[p--];
        res+=w;to[j]=t;
    } 
    // cerr<<res<<"\n";
    return res;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
    long long ans=WORK();
    // cerr<<ans<<"\n";
    if(ans){ cout<<ans<<"\n";return;}
    for(int i=1;i<=3;i++) ans=max(work(i),ans);
    cout<<ans<<"\n";
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}