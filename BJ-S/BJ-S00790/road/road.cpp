#include<iostream>
#include<vector>
using namespace std;
const int N = 1e4 +7 ;
const int M = 1e6 + 7 ;
const int K = 15 ;
long long n , m , k ;

struct node{
    long long x , w ;
};
vector<node>e[N];
long long c[K];
long long a[K][N];

void build()
{
    for( int x = 1 ; x <= k ; x++ )
    {
        for( int i = 1 ; i <= n ; i++ )
        {
            for( int j = i + 1 ; j <= n ; j++ )
            {
                e[i].push_back({j, c[x] + a[x][i] +a[x][j] });
            }
        }
    }
}

bool cmp(node x , node y )
{
    return x.w < y.w ;
}

long long ans = 0 ;
long long fa[N];

int findfa( int x )
{
    return fa[x] == x ? x : fa[x] = findfa(fa[x]);
}

void merge(int a , int b )
{
    fa[findfa(a)] = fa[findfa(b)];
}

void prim()
{

    for( int i = 1 ; i <= n ; i++ )fa[i] = i ;
    for(int i = 1 ; i <= n ; i++ )
    {
        long long minn = 1e18 ;
        int cur = -1 ;
        for( node j : e[i] )
        {
            if( findfa(i) != findfa(j.x) )
            {
                if( minn > j.w )
                {
                    minn = j.w ;
                    cur = j.x;
                }
            }
        }
        if(cur == -1)continue;
        merge(i,cur);
        ans += minn ;
    }
}

int main()
{
    freopen("road.in" ,"r" ,stdin);
    freopen("road.out" , "w" , stdout );
    cin >> n >> m >> k ;
    for(int i = 1 ; i <= m ; i++ )
    {
        int u , v , w ;
        cin >> u >> v >>w ;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i = 1 ; i <= k ; i++ )
    {
        cin >> c[i];
        for( int j = 1 ; j <= n ; j++ )
        {
            cin >>a[i][j];
        }
    }
    build();
    prim();
    cout <<ans ;

    return 0 ;
}