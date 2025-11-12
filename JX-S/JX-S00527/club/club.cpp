#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=4e18+25;
const int N=1e5+25;
int f[N][5];
int a[N][5],n;
int cnt[5];
int d[N],ans=0;
inline int fmax(int a,int b,int c){return max(a,max(b,c));}
inline void check(){
    memset(cnt,0,sizeof(cnt));
    int sum=0;
    for(int i=1;i<=n;i++){
        cnt[d[i]]++;
        sum+=a[i][d[i]];
    }
    int lim=(n>>1);
    if(cnt[1]<=lim&&cnt[2]<=lim&&cnt[3]<=lim)ans=max(ans,sum);
}
inline bool che(){
    memset(cnt,0,sizeof(cnt));
    int lim=(n>>1);
    for(int i=1;i<=n;i++)
        cnt[d[i]]++;
    if(cnt[1]<=lim&&cnt[2]<=lim&&cnt[3]<=lim)return 1;
    return 0;
}
inline void dfs(int x,int j){
    d[x]=j;
    for(int i=x+1;i<=n;i++)d[i]=0;
    if(!che()){return;}
    if(x==n){
        check();
        return;
    }
    for(int i=1;i<=3;i++)
        dfs(x+1,i);
}
inline void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
            cin>>a[i][j];
    if(n>30){
     cnt[1]=0,cnt[2]=0,cnt[3]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++){
            f[i][j]=fmax(f[i-1][1],f[i-1][2],f[i-1][3])+a[i][j];
        }

    cout<<fmax(f[n][1],f[n][2],f[n][3])<<'\n';
    }else{
        ans=0;
        memset(d,0,sizeof(d));
        dfs(0,0);
        cout<<ans<<'\n';
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _;cin>>_;
    while(_--)solve();
}
