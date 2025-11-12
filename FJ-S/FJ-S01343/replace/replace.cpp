#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
const int Siz=1<<18;char buf[Siz],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,Siz,stdin),p1==p2)?EOF:*p1++
int read(){
    int a=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') a=a*10+ch-'0',ch=getchar();
    return a;
}
const int N=2e5+10,M=5e6+10,P=998244853,B=37;
int n,q,m,ch[M][26],cnt,s[2][M],a[N][2],b[N][2],fa[M];map<pair<int,int>,pair<int,int> >mp;vector<int>vv[M],w,v[M];bool vis[N];
int ans[N],dfn[M],siz[M],id;
int readc(int *s){
    int t=0;char ch=getchar();while(ch<'a'||ch>'z') ch=getchar();
    while(ch>='a'&&ch<='z') s[t++]=ch-'a',ch=getchar();return t;
}
int hsh(int *s,int l,int r){
    int a=0;for(int i=l;i<r;i++) a=(1ll*a*B+s[i]+1)%P;return a;
}
void solve(int ___){
    m=readc(s[0]);if(m!=readc(s[1])) return;int ans=0;
    int l=0,r=m;while(l<m&&s[0][l]==s[1][l]) l++;while(s[0][r-1]==s[1][r-1]) r--;
    // printf("%d %d\n",l,r);
    pair<int,int>h={hsh(s[0],l,r),hsh(s[1],l,r)};pair<int,int>rt;
    if(!mp.count(h)) return;rt=mp[h];//printf("%d %d\n",rt.fir,rt.sec);
    int t=rt.fir;vv[t].push_back(___);
    for(int i=l-1;~i;i--) if(ch[t][s[0][i]]){
        t=ch[t][s[0][i]];
    }else break;//printf("\n");
    b[___][0]=t;
    t=rt.sec;
    for(int i=r;i<m;i++) if(ch[t][s[0][i]]){
        t=ch[t][s[0][i]];
    }else break;//printf("\n");
    b[___][1]=t;//printf("%d %d\n",b[___][0],b[___][1]);
}
void dfs(int t){
    siz[t]=1,dfn[t]=++id;for(int i=0;i<26;i++) if(ch[t][i]) dfs(ch[t][i]),siz[t]+=siz[ch[t][i]];
}
int lbt(int x){return x&-x;};struct BIT{
    int e[M];void add(int i,int k){while(i<=cnt) e[i]+=k,i+=lbt(i);}
    int query(int i){int ans=0;while(i) ans+=e[i],i-=lbt(i);return ans;}
}Tr;
struct qwq{
    int id,h,l,r,fl;
};vector<qwq>vec;
signed main(){
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    n=read(),q=read();for(int k=1;k<=n;k++){
        m=readc(s[0]),m=readc(s[1]);int l=0,r=m;
        while(l<m&&s[0][l]==s[1][l]) l++;while(r&&s[0][r-1]==s[1][r-1]) r--;
        if(l==m) continue;
        pair<int,int>h={hsh(s[0],l,r),hsh(s[1],l,r)};pair<int,int>rt;
        if(mp.count(h)) rt=mp[h];else{rt=mp[h]={cnt+1,cnt+2},cnt+=2;}
        int t=rt.fir;v[t].push_back(k);
        for(int i=l-1;~i;i--) if(ch[t][s[0][i]]) t=ch[t][s[0][i]];
            else{cnt++;ch[t][s[0][i]]=cnt,fa[cnt]=t,t=cnt;}a[k][0]=t;
        t=rt.sec;for(int i=r;i<m;i++) if(ch[t][s[0][i]]) t=ch[t][s[0][i]];
            else{cnt++;ch[t][s[0][i]]=cnt,fa[cnt]=t,t=cnt;}a[k][1]=t;
    }
    for(int i=1;i<=q;i++) solve(i);
    for(int rt=1;rt<=cnt;rt++) if(vv[rt].size()){
        id=0;dfs(rt);id=0;dfs(rt+1);vec.clear();
        // for(int i:v[rt]) printf("%d\n",i);
        for(int i:vv[rt]) vec.push_back({i,dfn[b[i][0]],dfn[b[i][1]],0,1});
        for(int i:v[rt]) vec.push_back({i,dfn[a[i][0]],dfn[a[i][1]],dfn[a[i][1]]+siz[a[i][1]],0}),
                         vec.push_back({i,dfn[a[i][0]]+siz[a[i][0]]-1,dfn[a[i][1]],dfn[a[i][1]]+siz[a[i][1]],2}),
        sort(vec.begin(),vec.end(),[](qwq a,qwq b){return a.h==b.h?a.fl<b.fl:a.h<b.h;});
        // for(qwq a:vec) printf("%d %d %d %d %d\n",a.id,a.h,a.l,a.r,a.fl);
        for(qwq a:vec) if(a.fl==0) Tr.add(a.l,1),Tr.add(a.r,-1);
        else if(a.fl==1) ans[a.id]=Tr.query(a.l);else Tr.add(a.l,-1),Tr.add(a.r,1);
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);return 0;
}