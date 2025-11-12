#include<bits/stdc++.h>
using namespace std;
struct st{
    long long u,v,w;
}road[1000005],a[200005];
bool cmp(st a,st b){return a.w<b.w;}
long long n,m,k,f[10015],total,cost[15],ans=1e13;
long long find(long long x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0' || ch>'9')ch=getchar();
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int b=1;b<=n;b++)f[b]=b;
    for(int b=1;b<=m;b++){
        road[b].u=read();
        road[b].v=read();
        road[b].w=read();
    }
    sort(road+1,road+1+m,cmp);
    for(int b=1;b<=m;b++){
        long long f1=find(road[b].u),f2=find(road[b].v);
        if(f1!=f2){
            f[f1]=f2;
            a[++total]=road[b];
        }
    }
    for(int b=n+1;b<=n+k;b++){
        cost[b-n]=read();
        for(int c=1;c<=n;c++){
            long long x=read();
            a[++total].u=b;
            a[total].v=c;
            a[total].w=x;
        }
    }
    sort(a+1,a+1+total,cmp);
    for(int b=0;b<(1<<k);b++){
        long long sum=0;
        for(int c=0;c<k;c++)if(b>>c&1)sum=sum+cost[c+1];
        for(int c=1;c<=n+k;c++)f[c]=c;
        for(int c=1;c<=total;c++){
            long long f1=find(a[c].u),f2=find(a[c].v);
            if((a[c].u<=n || b>>a[c].u-n-1&1) && f1!=f2){
                sum=sum+a[c].w;
                f[f1]=f2;
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}