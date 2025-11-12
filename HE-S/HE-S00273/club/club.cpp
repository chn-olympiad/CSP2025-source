#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
   int v,t;
}a[N][4];
int aa[N][4];
node d[N];
int p[4];
int c[N];
bool cmp(node a,node b){
    return a.v<b.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j].v);
                a[i][j].t=j;
                aa[i][j]=a[i][j].v;
            }
            if(a[i][2].v<a[i][3].v)swap(a[i][2],a[i][3]);
            if(a[i][1].v<a[i][2].v)swap(a[i][1],a[i][2]);
            if(a[i][2].v<a[i][3].v)swap(a[i][2],a[i][3]);
            ans+=a[i][1].v;
        }
        //sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            c[i]=a[i][1].t;
            p[a[i][1].t]++;
        }
        int f=0;
        if(p[1]>n/2)f=1;
        if(p[2]>n/2)f=2;
        if(p[3]>n/2)f=3;
        for(int i=1;i<=n;i++){
            d[i].v=a[i][1].v-a[i][2].v;
            d[i].t=i;
        }
        //for(int i=1;i<=n;i++){
        //    cout<<d[i].t<<" "<<d[i].v<<endl;
        //}
        //cout<<ans<<" "<<p[1]<<" "<<p[2]<<" "<<p[3]<<endl;
        sort(d+1,d+n+1,cmp);
        int eeeee=p[f];
        for(int i=1;i<=n;i++){
            int u=d[i].t;
            if(p[f]<=n/2)break;
            if(a[u][1].t!=f)continue;
            //cout<<d[i].t<<" "<<d[i].v<<endl;
            p[a[u][1].t]--;
            p[a[u][2].t]++;
            ans-=a[u][1].v;
            ans+=a[u][2].v;
            c[u]=a[u][2].t;
        }
        //buding
        int ff=0;
        if(n%2==1&&(p[1]==0||p[2]==0||p[3]==0)){
            if(p[1]==0)ff=1;
            if(p[2]==0)ff=2;
            if(p[3]==0)ff=3;
        }
        int res=2e9;
        if(ff!=0){
            for(int i=1;i<=n;i++){
                int xx=0;
                res=min(res,aa[i][c[i]]-aa[i][ff]);
            }
            printf("%d\n",ans-res);
            //cout<<ans;
        }
        else printf("%d\n",ans);
    }
    return 0;
}
