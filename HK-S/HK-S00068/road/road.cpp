#include <bits/stdc++.h>
using namespace std ;
#define int long long
vector <tuple<int,int,int>> adj ;
vector <pair<int,int>> adj2[13] ;
int C[13] ;
int gp[10003] ;
int dsu(int x){
    if (x==gp[x]) return x ;
    gp[x]=dsu(gp[x]) ;
    return gp[x] ;
}
void solve(){
    int N,M,K,i,j ;
    scanf("%lld%lld%lld",&N,&M,&K) ;
    adj.clear() ;
    for (i = 1 ; i <= K ; i ++) adj2[i].clear() ;
    for (i = 0 ; i < M ; i ++){
        int a,b,c ;
        scanf("%lld%lld%lld",&a,&b,&c) ;
        adj.push_back({c,a,b}) ;
    }
    sort(adj.begin(),adj.end()) ;
    for (i = 1 ; i <= K ; i ++){
        scanf("%lld",&C[i]) ;
        for (j = 1 ; j <= N ; j ++){
            int x ;
            cin >> x ;
            adj2[i].push_back({x,j}) ;
        }
        sort(adj2[i].begin(),adj2[i].end()) ;
    }
    int mn=LLONG_MAX/4 ;
    for (i = 0 ; i < (1<<K) ; i ++){
        int tt=0 ;
        int tk=0 ;
        for (j = 1 ; j <= K ; j ++){
            if ((1<<(j-1))&i) tt+=C[j],tk++ ;
        }
        for (j = 1 ; j <= N+K ; j ++) gp[j]=j ;
        vector <int> ptr(K+3,0) ;
        int ptr1=0 ;
        for (int k = 0 ; k < N+tk-1 ; k ++){
            while (ptr1<(int)adj.size()&&dsu(get<1>(adj[ptr1]))==dsu(get<2>(adj[ptr1]))) ptr1++ ;
            for (j = 1 ; j <= K ; j ++){
                if ((1<<(j-1))&i){
                    while (ptr[j]<(int)adj2[j].size()&&dsu(N+j)==dsu((adj2[j][ptr[j]]).second)) ptr[j]++ ;
                }
            }

            int mnn=LLONG_MAX/4 ;
            if (ptr1<(int)adj.size()) mnn=min(mnn,get<0>(adj[ptr1])) ;
            for (j = 1 ; j <= K ; j ++){
                if ((1<<(j-1))&i){
                    if (ptr[j]<(int)adj2[j].size()) mnn=min(mnn,(adj2[j][ptr[j]]).first) ;
                }
            }
            bool ok=0 ;
            if (ptr1<(int)adj.size()) if (mnn==get<0>(adj[ptr1])){
                gp[dsu(get<1>(adj[ptr1]))]=dsu(get<2>(adj[ptr1])) ;
                ok=1 ;
            }
            for (j = 1 ; j <= K ; j ++){
                if (ok) break ;
                if ((1<<(j-1))&i){
                    if (ptr[j]<(int)adj2[j].size()) if (mnn==(adj2[j][ptr[j]]).first){
                        gp[dsu(N+j)]=dsu((adj2[j][ptr[j]]).second) ;
                        ok=1 ;
                    }
                }
            }
            tt+=mnn ;
        }
        mn=min(mn,tt) ;
    }
    printf("%lld\n",mn) ;
}
signed main(){
    freopen("road.in","r",stdin) ;
    freopen("road.out","w",stdout) ;
    int T ;
    // cin >> T ;
    T=1 ;
    while (T--) solve() ;
    return 0 ;
}