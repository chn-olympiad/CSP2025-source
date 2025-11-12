#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N=1e6+1000;
int fa[N];
int cnt;
int vis[N];
int c[11000];
int aaa[N][67];
struct op{
    int u;
    int v;
    int z;
    int q;
}a[N];
int find(int x){
    if(fa[x]!=x){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
bool cmp(op x,op y){
    return x.z<y.z;
}
void solve1(){
       for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(a+1,a+m+1,cmp);
    int ans=0;
    int cnt=0;
    for(int i=1;i<=m;i++){
           // cout<<a[i].z<<" ";
        int uu=find(a[i].u);
        int vv=find(a[i].v);
        if(uu!=vv){
            uu=fa[vv];
            cnt++;
            ans+=a[i].z;
        }
        if(cnt==n-1){
            break;
        }
    }
     cout<<ans;
}
void solve2(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(a+1,a+cnt+1,cmp);
    int ans=0;
    int cnt=0;
    for(int i=1;i<=cnt;i++){
        // cout<<a[i].z<<" ";
        int uu=find(a[i].u);
        int vv=find(a[i].v);
        int qq=a[i].q;
        vis[qq]=1;
        if(uu!=vv){
            uu=fa[vv];
            cnt++;
            ans+=a[i].z;
        }
        if(cnt==n+k-1){
            break;
        }
    }
    for(int i=0;i<=k;i++){
        if(vis[i]){
            ans-=c[i];
        }
    }
     cout<<ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].z;
    }
    cnt=m+1;
    int pop=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>aaa[i][j];
            if(j==1){
                c[i]=aaa[i][j];
                pop+=c[i];
            }
            else{
                a[cnt].u=n+cnt-m;
                a[cnt].v=j-1;
                a[cnt].z=aaa[i][j];
                a[cnt].q=i;
                cnt++;
            }
        }
    }
    if(k==0){
        solve1();
    }
    else{
      solve2();
    }
    return 0;
}
