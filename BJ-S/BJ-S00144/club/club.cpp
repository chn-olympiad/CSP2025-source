#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct node{
    int maxn,delta,pos;
};
node ps[100005];
bool cmp(node a,node b){
    return a.delta<b.delta;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ans=0,p[3]={0,0,0};
        for(int i=0;i<n;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            int k1=max(a,max(b,c));
            int k2,k3;
            if(k1==a){
                k2=min(k1-b,k1-c);
                k3=1;
            }
            else if(k1==b){
                k2=min(k1-a,k1-c);
                k3=2;
            }
            else{
                k2=min(k1-b,k1-a);
                k3=3;
            }
            ps[i].maxn=k1;
            ps[i].delta=k2;
            ps[i].pos=k3;
            //cout<<k1<<' '<<k2<<' '<<k3<<'\n';
            p[k3-1]++;
            ans+=k1;
        }

        if(p[0]<=n/2&&p[1]<=n/2&&p[2]<=n/2){
            printf("%d\n",ans);
            continue;
        }
        int mo,l;
        if(p[0]>n/2){
            mo=1;
        }
        else if(p[1]>n/2){
            mo=2;
        }
        else{
            mo=3;
        }
        sort(ps,ps+n,cmp);
        int o=0;
        for(int i=0;i<n;i++){
            if(ps[i].pos!=mo) continue;
            ans-=ps[i].delta;
            o++;
            if(o==p[mo-1]-n/2) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
