#include<bits/stdc++.h>

#define mkp std::make_pair

int n,q;

struct Node{
    int p[26],fail;
    int len;
    Node(){
        memset(p,0,sizeof(p));
        fail=len=0;
    }
};

int qu[5000005],fr,bk;
int dl[5000005],dr[5000005],idx;
std::vector<int> ch[5000005];
std::vector<std::pair<int,int> > tv;

struct AC{
    std::vector<int> pos;
    std::vector<Node> t;  
    int ins(std::vector<char> s){
        int p=0;
        for(int i=0;i<s.size();i++){
            if(!t[p].p[s[i]-'a']){
                t[p].p[s[i]-'a']=t.size(),t.push_back(Node());
                t[t[p].p[s[i]-'a']].len=t[p].len+1;
            }
            p=t[p].p[s[i]-'a'];
        }
        pos.push_back(p);
        return p;
    }
    AC(){
        t.push_back(Node());
    }
    void gfail(){
        fr=1,bk=0;
        t[0].fail=0;
        for(int i=0;i<26;i++) if(t[0].p[i]) t[t[0].p[i]].fail=0,qu[++bk]=t[0].p[i];
        while(fr<=bk){
            int u=qu[fr++];
            for(int i=0;i<26;i++){
                if(!t[u].p[i]) t[u].p[i]=t[t[u].fail].p[i];
                else t[t[u].p[i]].fail=t[t[u].fail].p[i],qu[++bk]=t[u].p[i];
            }
        }
        return;
    }
    int mat(std::vector<char> s){
        int p=0;
        for(int i=0;i<s.size();i++) p=t[p].p[s[i]-'a'];
        return p;
    }
};

AC ad,af[200005],ab[200005];
std::vector<std::pair<std::pair<int,int>,int> > qv[200005];
std::vector<std::pair<std::pair<int,int>,std::pair<int,int> > > cv;

int mp[5000005],mc;
char s[5000005],t[5000005];
int rk[200005];
int ans[200005];

int nid;
bool cmp(int x,int y){
    return af[nid].pos[x]<af[nid].pos[y];
}

void dfs(int u){
    dl[u]=++idx;
    for(int v:ch[u]) dfs(v);
    dr[u]=idx;
    return;
}

int ss[5000005];

int lowbit(int x){
    return x&(-x);
}
const int U=5000000;
void add(int pos,int val){
    while(pos<=U) ss[pos]+=val,pos+=lowbit(pos);
    return;
}
int qry(int pos){
    int res=0;
    while(pos) res+=ss[pos],pos-=lowbit(pos);
    return res;
}
void add(int l,int r,int v){
    add(l,v),add(r+1,-v);
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);

    freopen("replace.in","r",stdin);
#ifndef AAA
    freopen("replace.out","w",stdout);
#endif

    std::cin>>n>>q;
    for(int i=1;i<=n;i++){
        std::cin>>(s+1);
        std::cin>>(t+1);
        int len=strlen(s+1);
        int fir,lst; fir=len+1,lst=0;
        for(int j=1;j<=len;j++) if(s[j]!=t[j]) fir=std::min(fir,j),lst=std::max(lst,j);
        if(!lst) continue;
        std::vector<char> diff;
        for(int j=fir;j<=lst;j++) diff.push_back(s[j]);
        for(int j=fir;j<=lst;j++) diff.push_back(t[j]);
        int u=ad.ins(diff);
        if(!mp[u]) mp[u]=++mc;
        std::vector<char> pre;
        for(int j=1;j<fir;j++) pre.push_back(s[j]);
        std::vector<char> end;
        for(int j=len;j>lst;j--) end.push_back(s[j]);
        af[mp[u]].ins(pre);
        ab[mp[u]].ins(end);
    }
    for(int i=1;i<=mc;i++) af[i].gfail(),ab[i].gfail();
    for(int i=1;i<=q;i++){
        std::cin>>(s+1)>>(t+1);
        int sn=strlen(s+1),tn=strlen(t+1);
        if(sn!=tn) continue;
        int fir,lst;
        fir=n+1,lst=0;
        for(int i=1;i<=sn;i++) if(s[i]!=t[i]){
            fir=std::min(fir,i),lst=std::max(lst,i);
        }
        std::vector<char> diff;
        for(int j=fir;j<=lst;j++) diff.push_back(s[j]);
        for(int j=fir;j<=lst;j++) diff.push_back(t[j]);
        int u=ad.mat(diff);
        if(!mp[u]||ad.t[u].len!=diff.size()) continue;
        std::vector<char> pre;
        for(int j=1;j<fir;j++) pre.push_back(s[j]);
        std::vector<char> end;
        for(int j=sn;j>lst;j--) end.push_back(s[j]);
        int x=af[mp[u]].mat(pre);
        int y=ab[mp[u]].mat(end);
        qv[mp[u]].push_back(mkp(mkp(x,y),i));
    }

    for(int i=1;i<=mc;i++){
        if(qv[i].empty()) continue;
        int nc=af[i].t.size(),m=qv[i].size();
        int cc=af[i].pos.size();
        for(int j=0;j<nc;j++) ch[j].clear();
        for(int j=0;j<nc;j++) if(j) ch[af[i].t[j].fail].push_back(j);
        idx=0; dfs(0);
        tv.clear();
        cv.clear();
        for(int j=0;j<cc;j++)
            tv.push_back(mkp(dl[af[i].pos[j]],dr[af[i].pos[j]]));
        for(int j=0;j<m;j++) qv[i][j].first.first=dl[qv[i][j].first.first];
        nc=ab[i].t.size();
        for(int j=0;j<nc;j++) ch[j].clear();
        for(int j=0;j<nc;j++) if(j) ch[ab[i].t[j].fail].push_back(j);
        idx=0; dfs(0);
        for(int j=0;j<m;j++) qv[i][j].first.second=dl[qv[i][j].first.second];

        int sz=af[i].pos.size();
        for(int j=0;j<sz;j++) rk[j]=j;
        std::sort(rk,rk+sz);
        for(int j=0;j<cc;j++){
            int l1=tv[j].first,r1=tv[j].second;
            int l2=dl[ab[i].pos[j]],r2=dr[ab[i].pos[j]];
            cv.push_back(mkp(mkp(l1,1),mkp(l2,r2)));
            cv.push_back(mkp(mkp(r1+1,-1),mkp(l2,r2)));
        }
        std::sort(cv.begin(),cv.end());
        std::sort(qv[i].begin(),qv[i].end());
        int p=0;
        for(int j=0;j<2*cc;j++){
            while(p<qv[i].size()){
                if(qv[i][p].first.first>=cv[j].first.first) break;
                ans[qv[i][p].second]=qry(qv[i][p].first.second);
                ++p;
            }
            add(cv[j].second.first,cv[j].second.second,cv[j].first.second);
        }
    }
    for(int i=1;i<=q;i++) std::cout<<ans[i]<<'\n';

    return 0;
}
