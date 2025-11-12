#include<bits/stdc++.h>
using namespace std;

int n,T,len[200010];
string s0[200010],s1[200010],t0,t1;
pair<int,int>lc[2000010],rc[2000010];
struct Node{
    int l,r; pair<int,int>w0,w1,wl,wr;
}a[200010];

inline bool No(pair<int,int>x,pair<int,int>y){
    return x.first!=y.first||x.second!=y.second;
}
inline pair<int,int>Hash(string s,int l,int r,bool chk){
    int x=0,y=0;
    if(!chk){
        for(int i=l;i<=r;++i){
            x=(114514ll*x+1919810*(s[i]-'a')+123456)%998244353;
            y=(20080622ll*y+20080308*(s[i]-'a')+234567)%19260817;
        }
        return {x,y};
    }
    for(int i=r;i>=l;--i){
        x=(114514ll*x+1919810*(s[i]-'a')+123456)%998244353;
        y=(20080622ll*y+20080308*(s[i]-'a')+234567)%19260817;
    }
    return {x,y};
}
inline Node work(string x,string y){
    int m=x.size(),l=0,r=m-1;
    pair<int,int>w0,w1,wl,wr;
    while(x[l]==y[l]&&l<m)++l;
    while(x[r]==y[r]&&r)--r;
    if(l>m)l=0,r=m-1;
    w0=Hash(x,l,r,0),w1=Hash(y,l,r,0),wl=Hash(x,0,l-1,1),wr=Hash(x,r+1,m-1,0);
    return Node{l,r,w0,w1,wl,wr};
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;++i)cin>>s0[i]>>s1[i],a[i]=work(s0[i],s1[i]),len[i]=s0[i].size();
    while(T--){
        cin>>t0>>t1;
        if(t0.size()!=t1.size()){ puts("0"); continue; }
        int m=t0.size(),ans=0; Node A=work(t0,t1); //printf("length=%d\n",m);
        for(int i=A.l-1,x=0,y=0;~i;--i){
            x=(114514ll*x+1919810*(t0[i]-'a')+123456)%998244353;
            y=(20080622ll*y+20080308*(t0[i]-'a')+234567)%19260817;
            lc[A.l-i]={x,y};
        }
        for(int i=A.r+1,x=0,y=0;i<m;++i){
            x=(114514ll*x+1919810*(t0[i]-'a')+123456)%998244353;
            y=(20080622ll*y+20080308*(t0[i]-'a')+234567)%19260817;
            rc[i-A.r]={x,y};
        }
        for(int i=1;i<=n;++i){

            /*if(i==1){
                printf("s:%d %d %d %d %d %d\n",a[i].l,a[i].r,a[i].w0.first,a[i].w1.first,a[i].wl.first,a[i].wr.first);
                printf("t:%d %d %d %d %d %d\n",A.l,A.r,A.w0.first,A.w1.first,A.wl.first,A.wr.first);
                printf("?:%d %d\n",lc[a[i].l].first,rc[m-a[i].r-1].first);
            }*/
            if(len[i]>m)continue;
            if(A.l<a[i].l||m-A.r<len[i]-a[i].r)continue;
            if(No(A.w0,a[i].w0)||No(A.w1,a[i].w1))continue;
            if(No(lc[a[i].l],a[i].wl)||No(rc[len[i]-a[i].r-1],a[i].wr))continue;
            ++ans;
            //printf("%d ",i);
        }
        //puts("");
        printf("%d\n",ans);
    }
}