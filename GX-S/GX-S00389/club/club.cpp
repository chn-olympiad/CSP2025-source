#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ans,n,a[100005][3],Max,maxa[100005];
bool vis[100005];int visc[3];
void f(int s,int cnt){
    if(s==n){
        ans=max(ans,cnt);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        for(int c=0;c<3;c++){
            if(visc[c]==Max)continue;
            visc[c]++;
            f(s+1,cnt+a[i][c]);
            visc[c]--;
        }
        vis[i]=0;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(a,sizeof(a),0);
        memset(vis,sizeof(a),0);
        memset(visc,sizeof(a),0);
        ans=0;
        cin>>n;
        Max=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            maxa[i]=max(max(a[i][0],a[i][1]),a[i][2]);
        }
        f(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
