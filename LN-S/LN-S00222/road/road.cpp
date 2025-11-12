#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
struct eg{
    int x,y,w;
}a[2000010];
int h[13][1000010];
int lg[10000];
bool b=1;
ll mi=1ll*1000000000*1000000000;
int f[150000];
bool cmp(eg x,eg y){
    return x.w<y.w;
}
int fi(int x){
    if(x==f[x]) return x;
    f[x]=fi(f[x]);
    return f[x];
}
void he(int x,int y){
    int fx=fi(x),fy=fi(y);
    f[fy]=fx;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
    }
    for(int i=2;i<=(1<<k);i++) lg[i]=lg[i/2]+1;
    for(int i=1;i<=k;i++){
        scanf("%d",&h[i][0]);
        if(h[i][0]!=0) b=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&h[i][j]);
            if(h[i][j]!=0) b=0;
        }
    }
    if(k==0){
        ll c=0;
        for(int i=1;i<=10010;i++) f[i]=i;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++){
            //if(on>=n-1) break;
            int u=a[i].x,v=a[i].y,w=a[i].w;
            if(fi(u)!=fi(v)){
                he(u,v);
                c+=w;
            }
        }
        cout<<c;
        return 0;
    }
    if(b){
        /*for(int i=1;i<=10010;i++) f[i]=i;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                he(j,i+n);
            }
        }
        ll c=0;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++){
            int u=a[i].x,v=a[i].y,w=a[i].w;
            if(fi(u)!=fi(v)){
                he(u,v);
                c+=w;
            }
        }
        cout<<c;*/
        cout<<0;
        return 0;
    }
    for(int g=0;g<=(1<<k)-1;g++){
        int t=m;
        int x=g;
        ll c=0;
        while(x){
            int y=lg[x-(x&(x-1))]+1;
            c+=h[y][0];
            for(int i=1;i<=n;i++){
                t++;
                a[t].x=i,a[t].y=y+n,a[t].w=h[y][i];
            }

            x=x&(x-1);
        }
        sort(a+1,a+t+1,cmp);
        int on=0;
        for(int i=1;i<=10010;i++) f[i]=i;
        for(int i=1;i<=t;i++){
            //if(on>=n-1) break;
            int u=a[i].x,v=a[i].y,w=a[i].w;
            if(fi(u)!=fi(v)){
                he(u,v);
                c+=w;
            }
        }
        //cout<<c<<'\n';
        mi=min(mi,c);
    }
    printf("%lld",mi);
    return 0;
}
