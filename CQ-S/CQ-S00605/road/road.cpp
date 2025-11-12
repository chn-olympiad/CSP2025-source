#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,s,a[14],b[10014],p,n,m,k,t[10014],i,j,in[10014],ou[10014];
int f(int x){
    if(t[x]==x) return x;
    return t[x]=f(t[x]);
}
struct l{
    int x,y,z;
}v[1100004];
bool cmp(l q,l w){
    return q.z<w.z;
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    if(k>10){
        printf("0");
        return 0;
    }
    for(i=1;i<=n;i++) b[i]=1,in[i]=1e18;
    for(i=1;i<=m;i++){
        scanf("%lld%lld%lld",&v[i].x,&v[i].y,&v[i].z);
        in[v[i].x]=min(in[v[i].x],v[i].z);
        in[v[i].y]=min(in[v[i].y],v[i].z);
    }
    for(i=1;i<=k;i++){
        scanf("%lld",&a[i]);
        for(j=1;j<=n;j++){
            v[++m].x=i+n;
            v[m].y=j;
            scanf("%lld",&v[m].z);
        } 
    }
    p=(1<<k);
    ans=1000000000000000000;
    sort(v+1,v+1+m,cmp);
    // for(i=1;i<=m;i++) cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<"\n";
    for(i=0;i<p;i++){
        s=0;
        for(j=1;j<=k;j++){
            b[j+n]=((1<<(j-1))&i);
            if(b[j+n]){
                s+=a[j];
            }
        }
        for(j=1;j<=n+k;j++) t[j]=j;
        for(j=1;j<=n;j++) b[j]=1;
        for(j=1;j<=m;j++){
            if(f(v[j].x)!=f(v[j].y)&&b[v[j].x]&&b[v[j].y]){
                s+=v[j].z;
                t[f(v[j].x)]=f(v[j].y);
                // cout<<v[j].x<<" "<<v[j].y<<"\n";
            }
        }
        // cout<<s<<"\n";
        ans=min(ans,s);
    }
    printf("%lld",ans);
    return 0;
}