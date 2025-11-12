#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,u,v,w,as;
struct P{
    int u,v,w,m,du,dv,dw,s;
    bool operator<(const P&rhs)const{return m>rhs.m;}
}p[N];
int main(){
#ifndef ASTRALFLARE_CE
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;u=v=w=as=0;
        for(int i=1;i<=n;++i){
            cin>>p[i].u>>p[i].v>>p[i].w;
            p[i].m=max(p[i].u,max(p[i].v,p[i].w));
            p[i].du=max(p[i].v-p[i].u,p[i].w-p[i].u);
            p[i].dv=max(p[i].u-p[i].v,p[i].w-p[i].v);
            p[i].dw=max(p[i].u-p[i].w,p[i].v-p[i].w);
        }
        sort(p+1,p+n+1);
        for(int i=1;i<=n;++i){
            if(p[i].u==p[i].m)++u,p[i].s=1;
            else if(p[i].v==p[i].m)++v,p[i].s=2;
            else ++w,p[i].s=3;
            as+=p[i].m;
        }
        if((u<<1)>n){
            sort(p+1,p+n+1,[](const P&lhs,const P&rhs){return lhs.du>rhs.du;});
            int c=u-n/2,i=0;
            while(c>0)if(p[++i].s==1)as+=p[i].du,--c;
        }else if((v<<1)>n){
            sort(p+1,p+n+1,[](const P&lhs,const P&rhs){return lhs.dv>rhs.dv;});
            int c=v-n/2,i=0;
            while(c>0)if(p[++i].s==2)as+=p[i].dv,--c;
        }else if((w<<1)>n){
            sort(p+1,p+n+1,[](const P&lhs,const P&rhs){return lhs.dw>rhs.dw;});
            int c=w-n/2,i=0;
            while(c>0)if(p[++i].s==3)as+=p[i].dw,--c;
        }
        cout<<as<<'\n';
    }
}