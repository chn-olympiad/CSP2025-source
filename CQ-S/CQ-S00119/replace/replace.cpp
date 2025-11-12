#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<ctime>
typedef long long ll;
constexpr int N{200000},L{5000000},C{26};
char __begin__;
char str[2][L+5];
int son[L+5][C];
int fail[L+5],go[L+5][C];
int dep[L+5],cnt[L+5];
int que[L+5];
char __end__;
int main() {
    fprintf(stderr,"memory: %.3lfMB\n",std::abs(&__end__-&__begin__)/1048576.);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    int tot{1};
    std::fill(son[0],son[0]+C,-1);
    cnt[0]=0;
    auto alloc([&](const int &x,const int &c)->int {
        if(son[x][c]!=-1) {
            return son[x][c];
        }
        std::fill(son[tot],son[tot]+C,-1);
        cnt[tot]=0;
        return son[x][c]=tot++;
    });
    for(int i=0;i!=n;i++) {
        scanf("%s%s",str[0],str[1]);
        int len{int(std::strlen(str[0]))};
        assert(std::strlen(str[1])==len);
        int pos{0};
        for(int j=0;j!=len;j++) {
            pos=alloc(pos,str[0][j]-'a');
            pos=alloc(pos,str[1][j]-'a');
        }
        ++cnt[pos];
    }
    std::cerr<<"tot = "<<tot<<'\n';
    for(int i=0;i!=tot;i++) {
        std::fill(go[i],go[i]+C,0);
        fail[i]=0;
    }
    int qb{0},qe{0};
    dep[0]=0;
    for(int i=0;i!=C;i++) {
        if(son[0][i]!=-1) {
            go[0][i]=son[0][i];
            dep[son[0][i]]=1;
            que[qe++]=son[0][i];
        }
        else {
            go[0][i]=0;
        }
    }
    while(qb!=qe) {
        int &u{que[qb++]};
        for(int i=0;i!=C;i++) {
            if(son[u][i]!=-1) {
                go[u][i]=son[u][i];
                fail[son[u][i]]=go[fail[u]][i];
                dep[son[u][i]]=dep[u]+1;
                que[qe++]=son[u][i];
            }
            else {
                go[u][i]=go[fail[u]][i];
            }
        }
    }
    std::cerr<<"timer: "<<std::clock()<<"ms\n";
    for(int i=0;i!=qe;i++) {
        int &u{que[i]};
        cnt[u]+=cnt[fail[u]];
    }
    for(int _=0;_!=q;_++) {
        scanf("%s%s",str[0],str[1]);
        int len{int(std::strlen(str[0]))};
        if(std::strlen(str[1])!=len) {
            puts("0");
            continue;
        }
        int fst{-1},lst{-1};
        for(int i=0;i!=len;i++) {
            if(str[0][i]!=str[1][i]) {
                fst=i;
                break;
            }
        }
        assert(fst!=-1);
        for(int i=len-1;i!=-1;i--) {
            if(str[0][i]!=str[1][i]) {
                lst=i;
                break;
            }
        }
        ll ans{0};
        int pos{0};
        for(int i=0;i!=len;i++) {
            pos=go[pos][str[0][i]-'a'];
            pos=go[pos][str[1][i]-'a'];
            if(i>=lst) {
                ans+=cnt[pos];
            }
        }
        pos=0;
        for(int i=fst+1;i!=len;i++) {
            pos=go[pos][str[0][i]-'a'];
            pos=go[pos][str[1][i]-'a'];
            if(i>=lst) {
                ans-=cnt[pos];
            }
        }
        printf("%lld\n",ans);
    }
    std::cerr<<"timer: "<<std::clock()<<"ms\n";
    return 0;
}