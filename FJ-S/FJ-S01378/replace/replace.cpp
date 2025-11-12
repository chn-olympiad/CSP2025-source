#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const i64 mod0=993244853,mod1=1025032627,bs0=31,bs1=37;
const i64 N=2e5+5;
int n,q,nq;
struct str{
    i64 pre[2],fmid[2],lmid[2],lst[2];
    int siz[3],id;
    bool op;
}a[N],e[N];
string s,t,qs[N][2];
namespace O_nq{
    i64 pw0[N],pw1[N];
    void solve(){
        for(int i=1;i<=nq;i++){
            //for()
            for(int j=1;j<=n;j++){
                if(e[i].fmid[0]!=a[j].fmid[0] || e[i].fmid[1]!=a[j].fmid[1] || e[i].siz[0]<a[j].siz[0] || e[i].siz[1]<a[j].siz[1] ||e[i].siz[2]<a[j].siz[2])continue;
                
            }
        }
    }
}
namespace SubB{
    const int L=5e6+5;
    int t[L],stk[N],ans[N],cnt=0;
    int qry(int u){
        int tot=0;
        while(u)tot+=t[u],u-=u&(-u);
        return tot;
    }
    void upd(int u,int k){
        for(;u<=L-5;u+=u&(-u))t[u]+=k;   
    }
    void solve(){
        for(int i=1;i<=n;i++)a[i].siz[2]++;
        for(int i=1;i<=nq;i++)e[i].siz[2]++;
        sort(e+1,e+nq+1,[](str x,str y){
            if(x.siz[1]!=y.siz[1])return x.siz[1]<y.siz[1];
            if(x.fmid[0]!=y.fmid[0])return x.fmid[0]<y.fmid[0];
            if(x.fmid[1]!=y.fmid[1])return x.fmid[1]<y.fmid[1];
            if(x.siz[0]!=y.siz[0])return x.siz[0]<y.siz[0];
            return x.siz[2]<y.siz[2];
        });
        sort(a+1,a+n+1,[](str x,str y){
            if(x.siz[1]!=y.siz[1])return x.siz[1]<y.siz[1];
            if(x.fmid[0]!=y.fmid[0])return x.fmid[0]<y.fmid[0];
            if(x.fmid[1]!=y.fmid[1])return x.fmid[1]<y.fmid[1];
            if(x.siz[0]!=y.siz[0])return x.siz[0]<y.siz[0];
            return x.siz[2]<y.siz[2];
        });int p=1;
        for(int i=1;i<=nq;i++){
            if(e[i].siz[1]!=e[i-1].siz[1] || e[i].fmid[0]!=e[i-1].fmid[0] || e[i].fmid[1]!=e[i-1].fmid[1])
                {while(cnt)upd(stk[cnt],-(qry(stk[cnt])-qry(stk[cnt]-1))),cnt--;}
            while(p<=n && (a[p].siz[1]!=e[i].siz[1] || a[p].fmid[0]!=e[i].fmid[0] || a[p].fmid[1]!=e[i].fmid[1]))p++;
            while(p<=n && (a[p].siz[1]==e[i].siz[1] && a[p].fmid[0]==e[i].fmid[0] && a[p].fmid[1]==e[i].fmid[1])
                  && a[p].siz[0]<=e[i].siz[0])upd(a[p].siz[2],1),stk[++cnt]=a[p].siz[2],p++;//cerr<<"p:"<<p<<'\n';
            ans[e[i].id]=qry(e[i].siz[2]);
            //for(int j=1;j<=10;j++)cerr<<qry(j)<<' ';
            //cerr<<'\n';
        }
        for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;bool subB=1;
    for(int i=1;i<=n;i++){
        cin>>s>>t;int len=s.length(),l=-1,r=-1;
        int sa=0,sb=0,ta=0,tb=0;
        for(int j=0;j<len;j++){
            if(s[j]=='a')sa++;
            if(s[j]=='b')sb++;
            if(t[j]=='a')ta++;
            if(t[j]=='b')tb++;
            if(s[j]!=t[j])l=(l==-1?j:l),r=j;
        }a[i].id=i;
        if(sa!=len-1 || sb!=1 || ta!=len-1 || tb!=1)subB=0;
        if(l==-1 && r==-1)a[i].op=1;
        else{
            a[i].siz[0]=l;a[i].siz[1]=r-l+1;a[i].siz[2]=len-r-1;
            for(int j=0;j<l;j++)
                a[i].pre[0]=(a[i].pre[0]*bs0%mod0+s[j]-'a')%mod0,
                a[i].pre[1]=(a[i].pre[1]*bs1%mod1+s[j]-'a')%mod1;
            for(int j=l;j<=r;j++)
                a[i].fmid[0]=(a[i].fmid[0]*bs0%mod0+s[j]-'a')%mod0,
                a[i].fmid[1]=(a[i].fmid[1]*bs1%mod1+s[j]-'a')%mod1;
            for(int j=l;j<=r;j++)
                a[i].lmid[0]=(a[i].lmid[0]*bs0%mod0+t[j]-'a')%mod0,
                a[i].lmid[1]=(a[i].lmid[1]*bs1%mod1+t[j]-'a')%mod1;
            for(int j=r+1;j<len;j++)
                a[i].lst[0]=(a[i].lst[0]*bs0%mod0+s[j]-'a')%mod0,
                a[i].lst[1]=(a[i].lst[1]*bs1%mod1+s[j]-'a')%mod1;
        }
    }
    sort(a+1,a+n+1,[](str x,str y){
        return x.op<y.op;
    });
    for(int i=1,x=0;i<=n;i++)x+=!a[i].op,n=(i==n?x:n);
    for(int i=1;i<=q;i++){
        cin>>s>>t;int len=s.length(),l=-1,r=-1;
        qs[i][0]=s;qs[i][1]=t;
        if(s.length()!=t.length()){e[i].op=1;continue;}
        int sa=0,sb=0,ta=0,tb=0;
        for(int j=0;j<len;j++){
            if(s[j]=='a')sa++;
            if(s[j]=='b')sb++;
            if(t[j]=='a')ta++;
            if(t[j]=='b')tb++;
            if(s[j]!=t[j])l=(l==-1?j:l),r=j;
        }
        if(sa!=len-1 || sb!=1 || ta!=len-1 || tb!=1)subB=0;
        e[i].id=i;
        e[i].siz[0]=l;e[i].siz[1]=r-l+1;e[i].siz[2]=len-r-1;
        //cerr<<l<<' '<<r<<' '<<len<<' '<<e[i].siz[2]<<endl;
        for(int j=0;j<l;j++)
            e[i].pre[0]=(e[i].pre[0]*bs0%mod0+s[j]-'a')%mod0,
            e[i].pre[1]=(e[i].pre[1]*bs1%mod1+s[j]-'a')%mod1;
        for(int j=l;j<=r;j++)
            e[i].fmid[0]=(e[i].fmid[0]*bs0%mod0+s[j]-'a')%mod0,
            e[i].fmid[1]=(e[i].fmid[1]*bs1%mod1+s[j]-'a')%mod1;
        for(int j=l;j<=r;j++)
            e[i].lmid[0]=(e[i].lmid[0]*bs0%mod0+t[j]-'a')%mod0,
            e[i].lmid[1]=(e[i].lmid[1]*bs1%mod1+t[j]-'a')%mod1;
        for(int j=r+1;j<len;j++)
            e[i].lst[0]=(e[i].lst[0]*bs0%mod0+s[j]-'a')%mod0,
            e[i].lst[1]=(e[i].lst[1]*bs1%mod1+s[j]-'a')%mod1;
    }
    sort(e+1,e+q+1,[](str x,str y){
        return x.op<y.op;
    });
    for(int i=1;i<=q;i++)nq+=!e[i].op;
    if(subB)SubB::solve();
    else O_nq::solve();
}