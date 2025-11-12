#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][5],cntx,cnty,cntz,ans;
struct Node{
    long long v,b;
}x[N],y[N],z[N];
bool cmp(Node l,Node r){
    return l.b>r.b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        ans=cntx=cnty=cntz=0;
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) x[++cntx].v=a[i][1],x[cntx].b=a[i][1]-max(a[i][2],a[i][3]);
            else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) y[++cnty].v=a[i][2],y[cnty].b=a[i][2]-max(a[i][1],a[i][3]);
            else if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1]) z[++cntz].v=a[i][3],z[cntz].b=a[i][3]-max(a[i][2],a[i][1]);
        }
        if(cntx>n/2){
            sort(x+1,x+cntx+1,cmp);
            for(int i=n/2+1;i<=cntx;i++) ans-=x[i].b;
        }
        if(cnty>n/2){
            sort(y+1,y+cnty+1,cmp);
            for(int i=n/2+1;i<=cnty;i++) ans-=y[i].b;
        }
        if(cntz>n/2){
            sort(z+1,z+cntz+1,cmp);
            for(int i=n/2+1;i<=cntz;i++) ans-=z[i].b;
        }
        for(int i=1;i<=cntx;i++) ans+=x[i].v;
        for(int i=1;i<=cnty;i++) ans+=y[i].v;
        for(int i=1;i<=cntz;i++) ans+=z[i].v;
        printf("%d\n",ans);
    }
    return 0;
}
