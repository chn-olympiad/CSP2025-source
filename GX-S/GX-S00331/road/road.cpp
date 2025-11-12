#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#define MXN 2000010
#define fs first
#define ll long long
using namespace std;
struct E{
    ll u,v,w;
}e[MXN];
int n,m,k,c,u,v,w,fa[1060],to[15][1030],cst[15],cv,ce;
bool operator >(E a,E b){
    return a.w>b.w;
}
priority_queue<E,vector<E>,greater<E> >q;
int fd(int x){
    if(fa[x]==x)return fa[x];
    return fa[x]=fd(fa[x]);
}
void mg(int x,int y){
    fa[fd(x)]=fd(y);
}
void build(int t){
    cv++;
    for(int i=1;i<=n;i++){
        ce++;
        e[ce].u=i;
        e[ce].v=cv;
        e[ce].w=to[t][i];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    bool flag=0;
    for(int i=1;i<=k;i++){
        cin>>cst[i];
        flag|=(cst[i]!=0);
        for(int j=1;j<=n;j++)cin>>to[i][j];
    }
    int p=pow(2,k)-1,ch=0;
    ll ans=1e18;
    if(flag==0)ch=p;
    for(ch;ch<=p;ch++){
        int tp=ch,plc=1;
        cv=n,ce=m;
        ll res=0;
        while(!q.empty())q.pop();
        while(tp){
            if(tp%2==1){build(plc);res+=cst[plc];}
            plc++;
            tp/=2;
        }
        for(int i=1;i<=ce;i++)q.push(e[i]);
        for(int i=1;i<=cv;i++)fa[i]=i;
        int ct=0;
        while(ct<cv-1){
            E tr=q.top();
            q.pop();
            if(fd(tr.u)==fd(tr.v))continue;
            mg(tr.u,tr.v);
            res+=tr.w;ct++;
        }
        ans=min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}
