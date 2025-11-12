#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;

int n,t;
int a[maxn][4],q[maxn][4],sz[4];
int ans=0;
int maxi[maxn],maxxi[maxn],maxp[maxn],maxxp[maxn];
void init(){
    ans=0;
    memset(q,0,sizeof(q));
    memset(sz,0,sizeof(sz));
    memset(maxi,0,sizeof(maxi));
    memset(maxxi,0,sizeof(maxxi));
    memset(maxp,0,sizeof(maxp));
    memset(maxxp,0,sizeof(maxxp));
}
void solve2(){
    priority_queue <int,vector<int>,greater<int> > qq;

    int j;
    for(int i=1;i<=3;i++){
        if(sz[i]>n/2) j=i;
    }
    for(int i=1;i<=sz[j];i++){
        int u=q[i][j];
        qq.push(maxi[u]-maxxi[u]);
    }
    for(int i=1;i<=sz[j]-n/2;i++){
        int u=qq.top();
        qq.pop();
        ans-=u;
    }
}
void solve(){
    init();
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            int u=a[i][j];
            if(u>maxi[i]){
                maxxi[i]=maxi[i],maxi[i]=u;
                maxxp[i]=maxp[i],maxp[i]=j;
            }
            else if(u==maxi[i]){
                maxxi[i]=u;
                maxxp[i]=j;
            }
            else if(u>maxxi[i]){
                maxxi[i]=u;
                maxxp[i]=j;
            }
        }
        ans+=maxi[i];
        sz[maxp[i]]++;
        q[sz[maxp[i]]][maxp[i]]=i;
    }
    if(sz[1]<=n/2 && sz[2]<=n/2 && sz[3]<=n/2){
        printf("%d\n",ans);
    }else{
        solve2();
        printf("%d\n",ans);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        solve();
    }

}

