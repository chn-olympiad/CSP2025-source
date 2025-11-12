/********************
 * @GavinCQTD
 * 2025/11/1 CSP-S
 * B. road
 * 1000 ms / 512 MB
********************/

#include <algorithm>
#include <iostream>
#include <bitset>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

namespace Gavin{
    int read(){
        int res=0;
        char c=getchar();
        while(!('0'<=c&&c<='9')){
            c = getchar();
        }
        while('0'<=c&&c<='9'){
            res = res*10+c-'0';
            c = getchar();
        }
        return res;
    }
    
    class DSU{
    private:
        int fa[10005],siz[10005];
        
    public:
        int find(int x){
            return x==fa[x]?x:fa[x]=find(fa[x]);
        }
        
        void unite(int x,int y){
            x = find(x);
            y = find(y);
            if(x==y){
                return;
            }
            if(siz[x]<siz[y]){
                swap(x,y);
                // ensure siz[x] >= siz[y]
            }
            fa[y] = x;
            siz[x] += siz[y];
        }
        
        void init(int n){
            for(int i=1;i<=n;i++){
                fa[i] = i;
                siz[i] = 1;
            }
        }

        DSU(){}
    };
    
    struct Element{
        int u,v,w;
    };
    
    int n,m,k,a[15][10005];
    ull ans=0;
    Element el[1000005];
    DSU dsu,dsu2;
    vector<int> co;
    vector<pair<int,int>> rec;
    bitset<15> bt;
    bitset<10005> tgi;
    
    int main(){
        n = read();
        m = read();
        k = read();
        for(int i=1;i<=m;i++){
            el[i].u = read();
            el[i].v = read();
            el[i].w = read();
        }
        for(int i=1;i<=k;i++){
            a[i][0] = read();
            for(int j=1;j<=n;j++){
                a[i][j] = read();
            }
        }
        
        dsu.init(n);
        co.push_back(0);
        
        stable_sort(el+1,el+m+1,[](Element x,Element y){
            return x.w<y.w;
        });
        
        ll tot=0;
        for(int i=1;i<=m;i++){
            if(dsu.find(el[i].u)!=dsu.find(el[i].v)){
                dsu.unite(el[i].u,el[i].v);
                co.push_back(i);
                tot += el[i].w;
                if(co.size()==n){
                    break;
                }
            }
        }
        
        if(k==0){
            cout << tot << "\n";
            return 0;
        }
        
        for(int i=n-1;i>=1;i--){
            dsu2.init(n);
            for(int j=1;j<=n-1;j++){
                if(i==j||tgi[j]){
                    continue;
                }
                dsu2.unite(el[co[j]].u,el[co[j]].v);
            }
            for(pair<int,int> ree:rec){
                dsu2.unite(ree.first,ree.second);
            }
            
            ll minv=1e18;
            int minvid=-1,_1=-1,_2=-1;
            for(int j=1;j<=k;j++){
                ll valu=1e18,valv=1e18;
                int valuid=-1,valvid=-1;
                for(int l=1;l<=n;l++){
                    if(dsu2.find(l)==dsu2.find(el[co[i]].u)){
                        if(a[j][l]<valu){
                            valu = a[j][l];
                            valuid = l;
                        }
                    }
                    else{
                        if(a[j][l]<valv){
                            valv = a[j][l];
                            valvid = l;
                        }
                    }
                }
                if(valu+valv+(bt[j]?0:a[j][0])<minv){
                    minv = valu+valv+(bt[j]?0:a[j][0]);
                    minvid = j;
                    _1 = valuid;
                    _2 = valvid;
                }
            }
            
            if(minv<el[co[i]].w){
                a[minvid][_1] = a[minvid][_2] = 0;
                tot -= el[co[i]].w;
                tot += minv;
                bt[minvid] = true;
                tgi[i] = true;
                rec.push_back(make_pair(_1,_2));
            }
            
            // cerr << i << " " << minv << " " << minvid << "\n";
        }
        
        cout << tot << "\n";

        return 0;
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    return Gavin::main();
}

