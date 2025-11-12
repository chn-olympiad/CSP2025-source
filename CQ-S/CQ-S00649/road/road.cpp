#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
namespace gtx{
    void read(char &x){x=getchar();while(x==' '||x=='\n'||x=='\r');}
    void write(char x){putchar(x);}
    void read(int &x){
        x=0;char ch;int h=1;
        do{ch=getchar();if(ch=='-')h=-h;}while(!isdigit(ch));
        while(isdigit(ch)) x*=10,x+=ch-'0',ch=getchar();
        x*=h;
    }
    void write(int x){
        if(x<0) putchar('-'),x=-x;
        int st[35]={};
        do st[++st[0]]=x%10,x/=10;while(x);
        while(st[0]) putchar(st[st[0]--]+'0');
    }
    void write(int x,char y){
        write(x);write(y);
    }
    #ifndef int
    void read(long long &x){
        x=0;char ch;int h=1;
        do{ch=getchar();if(ch=='-')h=-h;}while(!isdigit(ch));
        while(isdigit(ch)) x*=10,x+=ch-'0',ch=getchar();
        x*=h;
    }
    void write(long long x){
        if(x<0) putchar('-'),x=-x;
        int st[35]={};
        do st[++st[0]]=x%10,x/=10;while(x);
        while(st[0]) putchar(st[st[0]--]+'0');
    }
    void write(long long x,char y){
        write(x);write(y);
    }
    #endif
    const int MAXN = 1e4+20;
    struct edge{
        int x,y,z;
    };
    vector<edge> v,now,t[MAXN];
    int n,m,k,a[MAXN];
    int fath[MAXN];
    int sz[MAXN];
    long long ans;
    void merge(int x,int y){
        if(sz[x]>sz[y]) swap(x,y);
        fath[x] = y;
        sz[y] += sz[x];
    }
    inline int get_father(int x){
        if(x==fath[x]) return x;
        return fath[x]=get_father(fath[x]);
    }
    long long tans;
    int tot;
    inline void dfs(int u){
        if(u>k){
            if(now.empty()) return;
            long long lst = tans;
            vector<edge> old;
            vector<edge>::iterator vv = v.begin(),nn = now.begin();
            while(vv!=v.end()||nn!=now.end()){
                if(vv==v.end()) break;
                else if(nn==now.end()) break;
                else if(vv->z<nn->z) old.push_back(*(vv++));
                else old.push_back(*(nn++));
            }
            iota(fath+1,fath+1+n+k,1);
            fill(sz+1,sz+1+n,1);
            for(auto i:old){
                int x = get_father(i.x);
                int y = get_father(i.y);
                if(x==y) continue;
                merge(x,y);
                tans += i.z;
            }
            if(tans<ans) ans = tans;
            tans = lst;
            tot++;
            return;
        }
        auto tmp = now;
        {
            vector<edge> old;
            vector<edge>::iterator vv = t[u].begin(),nn = now.begin();
            iota(fath+1,fath+1+n+k,1);
            fill(sz+1,sz+1+n,1);
            while(vv!=t[u].end()||nn!=now.end()){
                int x,y;edge i;
                if(vv==t[u].end()) i=*nn,x=nn->x,y=nn->y,nn++;
                else if(nn==now.end()) i=*vv,x=vv->x,y=vv->y,vv++;
                else if(vv->z<nn->z) i=*vv,x=vv->x,y=vv->y,vv++;
                else i=*nn,x=nn->x,y=nn->y,nn++;
                x = get_father(x);
                y = get_father(y);
                if(x==y) continue;
                merge(x,y);
                old.push_back(i);
            }
            // 时刻保持只有O(n)条边
            now = old;
        }
        tans += a[u];
        if(tans<ans) dfs(u+1);
        now = tmp;
        tans -= a[u];
        dfs(u+1);
    }
    signed main(){
        read(n);read(m);read(k);
        vector<edge> old;
        for(int i = 1;i<=m;i++){
            int x,y,z;
            read(x);read(y);read(z);
            old.push_back({x,y,z});
        }
        sort(old.begin(),old.end(),[](edge a,edge b){
            return a.z<b.z;
        });
        iota(fath+1,fath+1+n,1);
        for(auto i:old){
            int x = get_father(i.x);
            int y = get_father(i.y);
            if(x==y) continue;
            fath[x] = y;
            v.push_back(i);
            ans += i.z;
        }
        for(int i = 1;i<=k;i++){
            read(a[i]);
            for(int j = 1;j<=n;j++){
                int z;
                read(z);
                t[i].push_back({i+n,j,z});
            }
            sort(t[i].begin(),t[i].end(),[](edge a,edge b){
                return a.z<b.z;
            });
        }
        dfs(1);
        write(ans);
        return 0;
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T = 1;
    // gtx::read(T);
    while(T--) gtx::main();
    // cerr << "\n\nTime:" << clock()*1000.0/CLOCKS_PER_SEC<< "ms\n";
    return 0;
}
/*
g++ road.cpp -o road -std=c++14 "-Wl,--stack=1000000000" -Wall -Wextra;if($?){echo "running";./road}

这么坑！
归并排序+最小生成树！！

这是CCF，应该跑得蛮快

122,400,000
*/