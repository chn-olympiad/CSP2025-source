#include<bits/stdc++.h>
constexpr int _=2e5+5,__=5e6+5;
int n,q,cnt,tot;
int t[__][26],h[__],nxt[_],g[_];
void Ins(int u,int x){
    g[++tot]=x;nxt[tot]=h[u];h[u]=tot;
}
char s[2][__];
bool c[_];
std::vector<int>b;
#define fio(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
int main(){
    fio("replace");
    scanf("%d%d",&n,&q);cnt=2;
    for(int p=1;p<=n;++p){
        scanf("%s%s",s[0]+1,s[1]+1);
        int m=std::strlen(s[0]+1),l=1,r=m;
        for(;l<=m&&s[0][l]==s[1][l];++l);
        if(l>m)continue;
        for(;s[0][r]==s[1][r];--r);
        int u=1;
        for(int i=l;i<=m;++i){
            int x=s[0][i]-'a';
            int &v=t[u][x];
            if(!v)v=++cnt;
            u=v;
        }
        Ins(u,p);
        u=2;
        for(int i=r;i;--i){
            int x=s[1][i]-'a';
            int &v=t[u][x];
            if(!v)v=++cnt;
            u=v;
        }
        Ins(u,p);
    }
    for(int p=1;p<=q;++p){
        scanf("%s%s",s[0]+1,s[1]+1);
        int m=std::strlen(s[0]+1),l=1,r=m;
        if(m!=std::strlen(s[1]+1)){printf("0\n");continue;}
        for(;l<=m&&s[0][l]==s[1][l];++l);
        if(l>m){printf("0\n");continue;}
        for(;s[0][r]==s[1][r];--r);
        int ans=0;
        int u=1;
        for(int i=l;i<=m;++i){
            int x=s[0][i]-'a';
            int &v=t[u][x];
            if(!v)break;
            u=v;
            if(i>=r)for(int j=h[u];j;j=nxt[j])
                b.push_back(g[j]),c[g[j]]=1;
        }
        u=2;
        for(int i=r;i;--i){
            int x=s[1][i]-'a';
            int &v=t[u][x];
            if(!v)break;
            u=v;
            if(i<=l)for(int j=h[u];j;j=nxt[j])
                ans+=c[g[j]];
        }
        for(int j:b)c[j]=0;
        b.clear();
        printf("%d\n",ans);
    }
}