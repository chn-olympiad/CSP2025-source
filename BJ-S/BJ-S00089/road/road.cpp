//long long !!!
#include<bits/stdc++.h>
using namespace std;
struct side{
    int u;
    int v;
    long long val;
    bool ava;
}sides[1050005];
int n,m,k,totn,totm,fa[10055];
long long c[15],cst,ans=1e18;
bool slct[15];
bool cmp(side a,side b){
    return a.val<b.val;
}
int findf(int p){
    if(fa[p]==p)return p;
    fa[p]=findf(fa[p]);
    return fa[p];
}
void mg(int a,int b){
    a=findf(a);
    b=findf(b);
    fa[a]=b;
    return;
}
void kru(long long totc){
    long long res=totc;
    for(int i=1;i<=totn;i++)fa[i]=i;
    for(int i=1;i<=totm;i++){
        if(!sides[i].ava)continue;
        if(findf(sides[i].u)!=findf(sides[i].v)){
            mg(sides[i].u,sides[i].v);
            res+=sides[i].val;
            //cout<<sides[i].u<<" "<<sides[i].v<<" is connected"<<endl;
            //for(int i=1;i<=totn;i++){
            //    cout<<fa[i]<<" ";
            //}
            //cout<<endl;
        }
    }
    ans=min(ans,res);
    //cout<<"res:"<<res<<" ans:"<<ans<<endl;
    return;
}
void mj(int p,long long totc){
    if(p>k){
        for(int i=1;i<=totm;i++){
            if(sides[i].u>n)sides[i].ava=slct[sides[i].u-n];
        }
        //for(int i=1;i<=k;i++)cout<<slct[k];
        //cout<<endl;
        kru(totc);
        return;
    }
    slct[p]=false;
    mj(p+1,totc);
    slct[p]=true;
    mj(p+1,totc+c[p]);
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    totn=n;
    totm=m;
    for(int i=1;i<=m;i++){
        cin>>sides[i].u>>sides[i].v>>sides[i].val;
        sides[i].ava=true;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        totn++;
        for(int j=1;j<=n;j++){
            cin>>cst;
            sides[++totm].u=totn;
            sides[totm].v=j;
            sides[totm].val=cst;
        }
    }
    sort(sides+1,sides+totm+1,cmp);
    mj(1,0);
    cout<<ans<<endl;
    return 0;
}
