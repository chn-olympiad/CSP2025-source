//40
#include<bits/stdc++.h>
using namespace std;
int k,n;
int sum,suma,sumb,sumc;
struct Node{
    int ai,bi,ci;
}a[100010];
struct MaxNode{
    int ma,indx,num;
}b[100010];
struct MidNode{
    int num,ma,indx;
}c[100010],d[100010];
bool cmp(MaxNode x,MaxNode y){
    return x.ma>y.ma;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>k;
    while(k--){
        sum=0;suma=0;sumb=0;sumc=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].ai,&a[i].bi,&a[i].ci);
            b[i].ma=max(max(a[i].ai,a[i].bi),a[i].ci);
            if(b[i].ma==a[i].ai) b[i].indx=1;
            if(b[i].ma==a[i].bi) b[i].indx=2;
            if(b[i].ma==a[i].ci) b[i].indx=3;
            b[i].num=i;
        }
        sort(b+1,b+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(b[i].indx==1 && suma<=n/2) suma++;sum+=b[i].ma;continue;
            if(b[i].indx==2 && sumb<=n/2) sumb++;sum+=b[i].ma;continue;
            if(b[i].indx==3 && sumc<=n/2) sumc++;sum+=b[i].ma;continue;
            if(b[i].indx==1) c[i].num=max(a[b[i].indx].bi,a[b[i].indx].ci);
            if(b[i].indx==2) c[i].num=max(a[b[i].indx].ai,a[b[i].indx].ci);
            if(b[i].indx==3) c[i].num=max(a[b[i].indx].ai,a[b[i].indx].bi);
            if(c[i].num==a[b[i].indx].ai && suma<=n/2) c[i].indx=1;suma++;sum+=c[i].num;continue;
            if(c[i].num==a[b[i].indx].bi && sumb<=n/2) c[i].indx=2;sumb++;sum+=c[i].num;continue;
            if(c[i].num==a[b[i].indx].ci && sumc<=n/2) c[i].indx=3;sumc++;sum+=c[i].num;continue;
            if(b[i].indx==2 && c[i].indx==3 || b[i].indx==3 && c[i].indx==2) d[i].num=a[b[i].indx].ai;
            if(b[i].indx==1 && c[i].indx==3 || b[i].indx==3 && c[i].indx==1) d[i].num=a[b[i].indx].bi;
            if(b[i].indx==1 && c[i].indx==2 || b[i].indx==2 && c[i].indx==1) d[i].num=a[b[i].indx].ci;
            if(d[i].num==a[b[i].indx].ai && suma<=n/2) suma++;sum+=d[i].num;
            if(d[i].num==a[b[i].indx].bi && sumb<=n/2) sumb++;sum+=d[i].num;
            if(d[i].num==a[b[i].indx].ci && sumc<=n/2) sumc++;sum+=d[i].num;
        }
        cout<<sum<<endl;
    }
    return 0;
}
