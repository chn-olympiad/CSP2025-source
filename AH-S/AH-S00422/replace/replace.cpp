#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define ll long long
#define ull unsigned ll
#define itn int
#define scf scanf
#define prf printf
#define gc getchar
#define pc putchar
#define fu(v,s,e) for(int v=s;v<=(e);v++)
#define fd(v,s,e) for(int v=s;v>=(e);v--)
using namespace std;
int _t;
inline int in(){
    itn x=0,f=1;
    char c=gc();
    while((c<'0'||c>'9')&&c!='-') c=gc();
    if(c=='-') f=-1,c=gc();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
    return f*x;
}
void out(int x){
    if(x>9) out(x/10);
    pc(x%10+'0');
}
inline void out(int x,char c){
    out(x),pc(c);
}
ull _hash(const char* str,int len){
    ull h=0;
    fu(i,1,len) h=h*29+str[i];
    return h;
}
ull _hash(const char* str1,const char* str2,int len){
    ull h=0;
    fu(i,1,len) h=h*29+str1[i],h=h*37+str2[i];
    return h;
}
int nxt[6000005][26],tot;
itn rr[6000005];
__gnu_pbds::gp_hash_table<int,int> tcnt[6000005];
struct trie{
    int rt;
    // trie(int _rt){rt=_rt;}
    int ins(const char *s,int n){
        int u=rt;
        fu(i,1,n){
            if(!nxt[u][s[i]]) nxt[u][s[i]]=++tot;
            u=nxt[u][s[i]];
        }
        // if(!cnt[u]) b[u]=++bt;
        return u;
    }
    void ins(const char *s,int n,int _to){
        int u=rt;
        fu(i,1,n){
            if(!nxt[u][s[i]]) nxt[u][s[i]]=++tot;
            u=nxt[u][s[i]];
        }
        // if(!cnt[u]) b[u]=++bt;
        // cnt[u]++;
        tcnt[u][_to]++;
        // return u;
    }
    void query1(const char *s,int n){
        int u=rt,res=0;
        for(const pair<int,int> x:tcnt[u]) rr[x.first]+=x.second;
        fu(i,1,n){
            u=nxt[u][s[i]];
            if(!u) break;
            for(const pair<int,int> x:tcnt[u]) rr[x.first]+=x.second;
            // res+=cnt[u];
        }
        // return res;
    }
    void del_query1(const char *s,int n){
        int u=rt,res=0;
        for(const pair<int,int> x:tcnt[u]) rr[x.first]-=x.second;
        fu(i,1,n){
            u=nxt[u][s[i]];
            if(!u) break;
            for(const pair<int,int> x:tcnt[u]) rr[x.first]-=x.second;
            // res+=cnt[u];
        }
        // return res;
    }
    int query2(const char *s,int n){
        int u=rt,res=rr[rt];
        // cerr<<u<<' '<<res<<'\n';
        fu(i,1,n){
            u=nxt[u][s[i]];
            if(!u) break;
            res+=rr[u];
            // cerr<<u<<' '<<res<<'\n';
        }
        return res;
    }
    void print(int u){
        // cerr<<u<<'\n';
        for(const pair<int,int> x:tcnt[u]) cerr<<x.first<<' '<<x.second<<'\n';
        fu(i,0,25) if(nxt[u][i]) prf("%d -%d> %d\n",u,i,nxt[u][i]),print(nxt[u][i]);
    }
}ht1[200005],ht2[200005];
int n,q,th1,th2;
char s1[5000005],s2[5000005],ss1[5000005],ss2[5000005];
__gnu_pbds::cc_hash_table<ull,int> it1,it2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // _t=in();
    // while(_t--){
    // }
    n=in(),q=in();
    while(n--){
        scf("%s%s",s1+1,s2+1);
        int ds=1,dl=1,len=strlen(s1+1);
        // assert(len<5000000);
        fu(i,1,len) s1[i]-='a',s2[i]-='a';
        while(s1[ds]==s2[ds]&&ds<=len) ds++;
        int de=len;
        while(s1[de]==s2[de]&&de>=ds) de--;
        dl=de-ds+1;
        // while((s1[ds+dl]^s2[ds+dl])&&ds+dl<=len) dl++;
        ull hh=_hash(s1+ds-1,s2+ds-1,dl);
        int ts1=ds-1,ts2=len-ds-dl+1;
        // cerr<<1;
        fu(i,1,ts1) ss1[i]=s1[ds-i];
        fu(i,1,ts2) ss2[i]=s1[ds+dl+i-1];
        // cerr<<2;
        if(it2.find(hh)==it2.end()) ht2[it2[hh]=++th2].rt=++tot;
        int u2=ht2[it2[hh]].ins(ss2,ts2);
        if(it1.find(hh)==it1.end()) ht1[it1[hh]=++th1].rt=++tot;
        ht1[it1[hh]].ins(ss1,ts1,u2);
        // fu(i,1,len) cerr<<int(s1[i])<<' ';
        // cerr<<'|';
        // fu(i,1,len) cerr<<int(s2[i])<<' ';
        // cerr<<'\n';
        // cerr<<ds<<' '<<dl<<'\n';
        // fu(i,1,ts1) cerr<<int(ss1[i])<<' ';
        // cerr<<'|';
        // fu(i,1,ts2) cerr<<int(ss2[i])<<' ';
        // cerr<<'\n';
        // cerr<<u2<<' '<<hh<<'\n';
    }
    // return 0;
    // fu(i,1,th1) ht1[i].print(ht1[i].rt);
    // fu(i,1,th2) ht2[i].print(ht2[i].rt);
    while(q--){
        scf("%s%s",s1+1,s2+1);
        int ds=1,dl=1,len=strlen(s1+1);
        fu(i,1,len) s1[i]-='a',s2[i]-='a';
        while(s1[ds]==s2[ds]) ds++;
        int de=len;
        while(s1[de]==s2[de]&&de>=ds) de--;
        dl=de-ds+1;
        ull hh=_hash(s1+ds-1,s2+ds-1,dl);
        int ts1=ds-1,ts2=len-ds-dl+1;
        fu(i,1,ts1) ss1[i]=s1[ds-i];
        fu(i,1,ts2) ss2[i]=s1[ds+dl+i-1];
        if(it1.find(hh)==it1.end()){
            prf("0\n");
            continue;
        }
        ht1[it1[hh]].query1(ss1,ts1);
        // cerr<<hh<<'\n';
        out(ht2[it2[hh]].query2(ss2,ts2),'\n');
        ht1[it1[hh]].del_query1(ss1,ts1);
    }
    // cerr<<'\n'<<clock()/1000.0<<"ms\n";
    return 0;
}
/*
希望评测姬发点力
*/