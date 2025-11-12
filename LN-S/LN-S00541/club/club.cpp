#include<bits/stdc++.h>
using namespace std;
int T,ans;
int n;
int v[4];
struct nnode{
    int x,ip;
};
bool cccmp(nnode x,nnode y){
    return x.x>y.x;
}
struct node{
    nnode a[4];
    void build(){
        a[1].ip=1;
        a[2].ip=2;
        a[3].ip=3;
    }
    void sot(){
        sort(a+1,a+4,cccmp);
        return;
    }
};
bool cmp(node x,node y){
    return x.a[1].x-x.a[2].x>y.a[1].x-y.a[2].x;
}
node a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        memset(v,0,sizeof(v));
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].a[1].x,&a[i].a[2].x,&a[i].a[3].x);
            a[i].build();
            a[i].sot();
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(v[a[i].a[1].ip]<n/2){
                v[a[i].a[1].ip]++;
                ans+=a[i].a[1].x;
            }else{
                ans+=a[i].a[2].x;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
