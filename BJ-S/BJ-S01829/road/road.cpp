#include<bits/stdc++.h>
#define ll long long
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x;
}
ll readl(){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x;
}
void write(ll x){
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
using namespace std;
int n,m,k,fa[10020],siz[10020],now[11];
ll c[11],ans;
int find(int x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    if(siz[y]>siz[x]){
        swap(x,y);
    }
    fa[y]=x;
    siz[x]+=siz[y];
}
struct line{
    int from,to;
    ll len;
    bool operator <(const line o)const{
        return len<o.len;
    }
};
vector<line> v,v2,vv[11],v3;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;i++){
        int from,to,len;
        from=read();
        to=read();
        len=readl();
        v.emplace_back((line){from,to,len});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        fa[i]=i;
        siz[i]=1;
    }
    for(int i=0;i<v.size();i++){
        int fx=find(v[i].from),fy=find(v[i].to);
        if(fx==fy){
            continue;
        }
        v2.emplace_back(v[i]);
        merge(fx,fy);
        ans+=v[i].len;
    }
    for(int i=1;i<=k;i++){
        c[i]=readl();
        for(int j=1;j<=n;j++){
            ll tmp;
            tmp=readl();
            vv[i].emplace_back((line){j,n+i,tmp});
        }
        sort(vv[i].begin(),vv[i].end());
    }
    for(int i=1;i<(1ll<<k);i++){
        v.clear();
        ll res=0;
        int cnt=0;
        now[0]=0;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                res+=c[j];
                cnt++;
                now[j]=0;
            }
        }
        while((int)v.size()<=(cnt+1)*n-1){
            line minn={0,0,LLONG_MAX};
            int minm=0;
            if(now[0]<v2.size()){
                minn=v2[now[0]];
                minm=0;
            }
            for(int j=1;j<=k;j++){
                if((i>>(j-1))&1){
                    if(now[j]<vv[j].size()){
                        if(vv[j][now[j]]<minn){
                            minn=vv[j][now[j]];
                            minm=j;
                        }
                    }
                }
            }
            now[minm]++;
            v.emplace_back(minn);
        }
        for(int j=1;j<=n+k;j++){
            fa[j]=j;
            siz[j]=1;
        }
        for(int j=0;j<v.size();j++){
            int fx=find(v[j].from),fy=find(v[j].to);
            if(fx==fy){
                continue;
            }
            merge(fx,fy);
            res+=v[j].len;
        }
        ans=min(ans,res);
    }
    write(ans);
    putchar('\n');
    return 0;
}
