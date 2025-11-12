#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define ll long long
#define frp freopen
#define  fio(in,out) frp(in,"r",stdin),frp(out,"w",stdout)
void bug(){cout<<endl;}
template<typename T,typename ... Ts>
void bug(T x,Ts ... y){cout<<x<<" ",bug(y...);}
template<typename T=int>
T read(){
    T res=0,f=1;char c;
    for(;(c=getchar())<'0'||c>'9';c=='-'?f=-f:0);
    while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0',c=getchar();
    return res*f;
}
int n,a[maxn][3],p[3],ans,id[maxn],sz[3],t[3];
struct dat{
    int x,y,i;
    bool operator<(const dat &b)const{
        return x<b.x;
    }
};
priority_queue<dat>q[3];
int cal(int x,int y){
    if(sz[x]>=n)return q[x].top().x+y;
    return y;
}
void upd(int i,int x){
    sz[x]+=2;
    q[x].push({a[i][(x+1)%3]-a[i][x],(x+1)%3,i}),q[x].push({a[i][(x+2)%3]-a[i][x],(x+2)%3,i}),ans+=a[i][x];
}
int main(){
    fio("club.in","club.out");
    int i,j,T=read(),x;
    while(T--)
    {
        n=read();ans=0;
        memset(sz,0,sizeof(sz));
        for(i=1;i<=n;++i)
        {
            for(j=0;j<3;++j)a[i][j]=read(),t[j]=a[i][j],p[j]=j;
            sort(p,p+3,[](int x,int y){
                return cal(x,t[x])>cal(y,t[y]);
            });//bug("!",i);
            x=p[0],id[i]=p[0];
            if(sz[x]>=n){
                auto nw=q[x].top();q[x].pop(),sz[x]-=2;
                ans+=nw.x,id[nw.i]=nw.y;
                upd(i,x);
            }
            else upd(i,x);
            for(j=0;j<3;++j)while(q[j].size()&&id[q[j].top().i]!=j)q[j].pop();
            
        }
        for(j=0;j<3;++j)while(q[j].size())q[j].pop();
        printf("%d\n",ans);
    }
    return 0;
}