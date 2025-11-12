#include<bits/stdc++.h>
using namespace std;
int n,m,ch[10000010][26],tot,dfn[10000010],out[10000010],preid[400010],sufid[400010],bl[400010];
char S[5000010],T[5000010];
struct R_{int xl,xr,yl,yr;};
struct Q_{int i,x,y;};
struct M_{int x,l,r,w;};
map<pair<int,int>,int>Sid;
vector<Q_>q[400010];
vector<R_>mdfs[400010];
int Sn,ans[200010];
inline int insert(char*s,int l,int r,bool rev){
   int u=1;
   if(!rev){
      for(int i=l;i<=r;i++){
         int&v=ch[u][s[i]-'a'];
         if(!v)v=++tot;u=v;
      }return u;
   }else{
      for(int i=r;i>=l;i--){
         int&v=ch[u][s[i]-'a'];
         if(!v)v=++tot;u=v;
      }return u;
   }
}
void dfs(int u){
   dfn[u]=++tot;
   for(int v:ch[u])if(v)dfs(v);
   out[u]=tot;
}
namespace ds{
int cnt[10000010];
inline void add(int p,int w){
   for(;p<=tot;p+=p&-p)cnt[p]+=w;
}
inline int ask(int p){
   int s=0;for(;p;p-=p&-p)s+=cnt[p];
   return s;
}
}
int main(){
   freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
   tot++;
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n+m;i++){
      scanf("%s%s",S+1,T+1);
      int N=strlen(S+1);
      int L=0,R;
      for(int j=1;j<=N;j++)if(S[j]!=T[j]){
         if(!L)L=j;R=j;
      }
      if(!L)continue;
      int char1=insert(S,L,R,false),char2=insert(T,L,R,false);
      if(!Sid.count({char1,char2}))Sid[{char1,char2}]=++Sn;
      bl[i]=Sid[{char1,char2}];
      preid[i]=insert(S,1,L-1,true);
      sufid[i]=insert(S,R+1,N,false);
   }
   tot=0,dfs(1);
   for(int i=1;i<=n;i++){
      mdfs[bl[i]].push_back({dfn[preid[i]],out[preid[i]],dfn[sufid[i]],out[sufid[i]]});
   }
   for(int i=n+1;i<=n+m;i++){
      q[bl[i]].push_back({i-n,dfn[preid[i]],dfn[sufid[i]]});
   }
   for(int i=1;i<=Sn;i++){
      vector<M_>mdf;
      for(R_ u:mdfs[i]){
         mdf.push_back({u.xl,u.yl,u.yr,1});
         mdf.push_back({u.xr+1,u.yl,u.yr,-1});
      }
      sort(begin(mdf),end(mdf),[](M_ x,M_ y){return x.x<y.x;});
      sort(begin(q[i]),end(q[i]),[](Q_ x,Q_ y){return x.x<y.x;});
      int j=0;
      for(Q_ u:q[i]){
         for(;j<mdf.size()&&mdf[j].x<=u.x;j++){
            ds::add(mdf[j].l,mdf[j].w),ds::add(mdf[j].r+1,-mdf[j].w);
         }ans[u.i]=ds::ask(u.y);
      }
      for(;j<mdf.size();j++){
         ds::add(mdf[j].l,mdf[j].w),ds::add(mdf[j].r+1,-mdf[j].w);
      }
   }
   for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
   return 0;
}