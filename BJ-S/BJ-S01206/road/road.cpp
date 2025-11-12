#include<bits/stdc++.h>
using namespace std;
int f[200005],sz[200005];
struct node{
    int u;
    int v;
    int w;
    int y;
} a[2000006];
int cu[15],c[15],w[15][100005],us[100005];
bool cmp(node a,node b){
    return a.w<b.w;
}
int fin(int p){
    int yp=p;
    while(f[p]!=p){
        p=f[p];
       
    } 
    while(f[yp]!=yp){
        yp=f[yp];
        f[yp]=p;
    }
    return p;
}
void merge(int a,int b){
    a=fin(a);
    b=fin(b);
    if(sz[a]<sz[b]){
        swap(a,b);
    }
    f[b]=a;
    sz[a]+=b;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,tot=0;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1; i<=n; i++){
        sz[i]=1;
        f[i]=i;
    }
    long long ans=0,sum=0;
    sort(a+1,a+m+1,cmp);
    for(int i=1; i<=m; i++){
        int u=a[i].u,v=a[i].v,w=a[i].w;
        if(sum==n-1){
            break;
        }
        if(fin(u)!=fin(v)){
            merge(u,v);
            us[++tot]=i;
            sum++;
        }
    }
    for(int i=1; i<=tot; i++){
        a[i]=a[us[i]];
    }
    int m2=m;
    long long sump=0;
    for(int i=1; i<=k; i++){
        cin>>c[i];
        sump+=c[i];
        for(int j=1; j<=n; j++){
            cin>>w[i][j];
            a[++m2].u=j;
            a[m2].v=n+i;
            a[m2].w=w[i][j];
            a[m2].y=i;
        }
    }
    m=m2;
    if(k==0||sump==0){
        sort(a+1,a+m+1,cmp);
        for(int i=1; i<=n+k; i++){
            sz[i]=1;
            f[i]=i;
        }
        long long ans=0,sum=0;
        for(int i=1; i<=m; i++){
            int u=a[i].u,v=a[i].v,w=a[i].w;
            if(sum==n+k-1){
                break;
            }
            if(fin(u)!=fin(v)){
                merge(u,v);
                ans=ans+w;
                sum++;
            }
        }
        cout<<ans;
    } else{
        sort(a+1,a+m+1,cmp);
        long long minn=1e18;
        for(int zy=0; zy<(1<<k); zy++){
            long long ans=0,sumh=0;
            for(int i=1; i<=k; i++){
                cu[i]=((zy>>(i-1))&1);
                //cout<<cu[i]<<" ";
                if(cu[i]==1){
                    ans=ans+c[i];
                    sumh++;
                }
            }
            for(int i=1; i<=n+k; i++){
                sz[i]=1;
                f[i]=i;
            }
            long long sum=0;
            for(int i=1; i<=m; i++){
                if(a[i].y!=0&&cu[a[i].y]==0) continue;
                int u=a[i].u,v=a[i].v,w=a[i].w;
                if(sum==n+sumh-1){
                    break;
                }
                if(fin(u)!=fin(v)){
                    //cout<<a[i].u<<"_"<<a[i].v<<endl;
                    merge(u,v);
                    ans=ans+w;
                    sum++;
                }
            }
            minn=min(minn,ans);
            //cout<<endl;
        }
        cout<<minn<<endl;
    }
    return 0;
}