#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int> ma;
ll n,m,k;
int f[10105];
ll a[10005],c;
struct node{
    ll u,v,w;
}e[1100100];
int read(){
    char ch=getchar();
    int orz=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9'){
        orz=orz*10+ch-'0';
    }
    return orz;
}
ll find(ll x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
bool cmp(node a,node b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;i++){
        e[i].u=read();
        e[i].v=read();
        e[i].w=read();
        ma[e[i].u*10000+e[i].v]=i;
        ma[e[i].v*10000+e[i].u]=i;
    }
    for(int i=1;i<=k;i++){
        c=read();
        for(int j=1;j<=n;j++){
            a[j]=read();
        }
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                    int kk=ma[j*10000+k];
                    if(!kk)continue;
                if(a[j]+a[k]<e[kk].w){
                    e[kk].w=a[j]+a[k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    sort(e+1,e+m+1,cmp);
    ll ans=0;
    for(int i=1;i<=m;i++){
        ll uuu=find(e[i].u);
        ll vvv=find(e[i].v);
        if(uuu==vvv)continue;
        f[uuu]=vvv;
        ans+=e[i].w;
    }
    cout<<ans;
    return 0;
}

