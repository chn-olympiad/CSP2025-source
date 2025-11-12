#include<bits/stdc++.h>
using namespace std;
int n,m,k,ls=1,l2,lo,u,s[10010],f[100010];
long long lans,ans=LONG_MAX;
bool cz[11];
struct p{
    int a,b,c;
}r[1000010],y[100010],x[100010];
void dfs(int a){
    if(f[f[a]]==f[a]) return;
    else{
        dfs(f[a]);
        f[a]=f[f[a]];
    }
}
bool cmp(p q,p w){
    return q.c<w.c;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int j=1;j<=n;j++) f[j]=j;
    for(int i=1;i<=m;i++) scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].c);
    sort(r+1,r+m+1,cmp);
    for(int i=1;i<=k;i++) for(int j=0;j<=n;j++){
        if(j!=0){
            scanf("%d",&y[i*n+j].c);
            y[i*n+j].a=i+n,y[i*n+j].b=j;
        }
        else scanf("%d",&s[i]);
    }
    for(int i=1;ls<n;i++){
        dfs(r[i].a);
        dfs(r[i].b);
        if(f[r[i].a]==f[r[i].b]) continue;
        else f[f[min(r[i].a,r[i].b)]]=f[max(r[i].a,r[i].b)],ls++,y[ls]=r[i];
    }
    sort(y+2,y+n*k+n+1,cmp);
    for(int o=0;o<(1<<k);o++){
        u=0,ls=1,l2=1,f[0]=0,f[1]=1,lo=o,lans=0;
        for(int i=1;i<=k;i++){
            if(lo%2==0) cz[i]=0;
            else  lans+=s[i],cz[i]=1,u++;
            lo/=2;
        }
        for(int j=2;j<=n*k+n;j++) f[j]=j;
        for(int i=2;l2<n*u+n;i++){
            if(y[i].a<=n) l2++,x[l2]=y[i];
            else if(cz[y[i].a-n]==1) l2++,x[l2]=y[i];
        }
        for(int i=2;ls<n+u;i++){
            dfs(x[i].a);
            dfs(x[i].b);
            if(f[x[i].a]==f[x[i].b]) continue;
            else f[f[min(x[i].a,x[i].b)]]=f[max(x[i].a,x[i].b)],ls++,lans+=x[i].c;
        }
        ans=min(ans,lans);
    }
    cout<<ans<<endl;
    return 0;
}
