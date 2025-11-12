#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=6e5+10;
int vis[maxn],cnt[3];
struct node{
    int x,id,comp;
}a[maxn];
int b[5][3];
bool cmp(node a,node b){
    return a.x>b.x;
}
void solve(){
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    int n;cin>>n;
    if(n==2){
        for(int i=1;i<=2;++i){
            for(int j=1;j<=3;++j){
                cin>>b[i][j];
            }
        }
    }
    if(n==2){
        int mx=INT_MIN;
        for(int i=1;i<=3;++i){
            for(int j=1;j<=3;++j){
                if(i!=j)mx=max(mx,b[1][i]+b[2][j]);
            }
        }
        cout<<mx<<endl;
        return;
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        int u,v,w;cin>>u>>v>>w;
        a[(i-1)*3+1]=node{u,i,1};
        a[(i-1)*3+2]=node{v,i,2};
        a[(i-1)*3+3]=node{w,i,3};
    }
    sort(a+1,a+1+3*n,cmp);
    int i=1,ct=0;
    while(i<=3*n){
        if(ct==n)break;
        if(!vis[a[i].id]&&cnt[a[i].comp]<n/2){
            ans+=a[i].x;
            cnt[a[i].comp]++;ct++;
            vis[a[i].id]=true;
            continue;
        }

        i++;
    }
    cout<<ans<<endl;

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
