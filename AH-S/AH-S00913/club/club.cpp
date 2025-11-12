#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct node{
    long long x[4],xma,xmi,xx;
}a[100005];
int vis[5];
bool cmp(node u,node v){
    //return u.xma-u.xx>v.xma-v.xx;
    //return u.xx-u.xmi>v.xx-v.xmi;
    if(u.x[1]-u.x[2]!=v.x[1]-v.x[2]) return u.x[1]-u.x[2]>v.x[1]-v.x[2];
    return u.x[2]-u.x[3]>v.x[2]-v.x[3];
}
bool cmpf(node u,node v){
    return u.x[1]>v.x[1];
}
bool cmpj(node u,node v){
    return u.x[1]-u.x[2]>v.x[1]-v.x[2];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        memset(vis,0,sizeof(vis));
        bool vis1=1,vis2=1;
        ans=0;
        for( int i=1;i<=n;i++ ){
            scanf("%lld%lld%lld",&a[i].x[1],&a[i].x[2],&a[i].x[3]);
            if(!(a[i].x[2]==0&&a[i].x[3]==0)) vis1=0;
            if(a[i].x[3]!=0) vis2=0;
            a[i].xma=max(a[i].x[1],max(a[i].x[2],a[i].x[3]));
            a[i].xmi=min(a[i].x[1],max(a[i].x[2],a[i].x[3]));
            a[i].xx=a[i].x[1]+a[i].x[2]+a[i].x[3]-a[i].xma-a[i].xmi;
        }
        if(vis1){
            sort(a+1,a+n+1,cmpf);
            for( int i=1;i<=n/2;i++ ) ans+=a[i].x[1];
            cout<<ans<<endl;
            continue;
        }
        if(vis2){
            sort(a+1,a+n+1,cmpj);
            for( int i=1;i<=n/2;i++ ) ans+=a[i].x[1];
            for( int i=n/2+1;i<=n;i++ ) ans+=a[i].x[2];
            cout<<ans<<endl;
            continue;
        }
        sort(a+1,a+n+1,cmp);
        for( int i=1;i<=n;i++ ){
            int p=0;
            for( int j=1;j<=3;j++ ){
                if(vis[j]<n/2&&(p==0||a[i].x[j]>a[i].x[p])) p=j;
            }
            vis[p]++;
            ans+=a[i].x[p];
        }
        cout<<ans<<endl;
    }
    return 0;
}
