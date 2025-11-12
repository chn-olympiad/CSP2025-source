#include<iostream>
using namespace std;
const int N= 505;
const int MOD = 998244353;
int n  , m ;
bool s[N];
int c[N];
long long ans = 0 ;

bool checka()
{
    for( int i = 1 ; i <= n ; i++ )
    {
        if(s[i]==false)return false;
    }
    return true;
}
bool vis[N];
int q[N];
void dfs( int step )
{
    if( step > n )
    {
        int sum = 0 ;
        int cnt = 0 ;
        for( int i = 1 ; i <= n ; i++ )
        {
            if( !s[i]  || cnt >= c[q[i]] )cnt++;
            else sum++;
        }
        if( sum >= m )
        {
            ans++;
        }
    }
    for( int i = 1 ; i <= n ; i++ )
    {
        if(vis[i])continue;
        vis[i] = true;
        q[step] = i ;
        dfs( step + 1 );
        vis[i] = false;
    }
}

int main()
{
   freopen("employ.in" ,"r" ,stdin);
   freopen("employ.out" , "w" , stdout );


    cin >>n >> m ;
    for(int i = 1 ; i <= n ; i++ )
    {
        char c ;
        cin >> c;
        s[i] = c -'0';
    }

    for(int i = 1 ; i <= n ; i++ )cin >> c[i] ;

    int w = 0 ;
    for(int i = 1 ; i <= n ; i++ )if(c[i] )w++;
    if(w<m)
    {
        cout <<0 ;
        return 0 ;
    }


    if( checka() )
    {
        int cnt = 0 ;
        for( int i = 1 ; i <= n ; i++ )if( c[i] == 0 )cnt++;

        if( n - cnt < m )
        {
            cout <<0 ;
            return ;
        }

        long long mul1 = 1 ;
        for( int i = 2 ; i <= cnt ; i++ )mul1 = mul1 * i % MOD ;
        long long mul2 = 1 ;
        for( int i = 2 ; i <= n - cnt ; i++ )mul2 = mul2 *i % MOD ;
        cout <<mul1 * mul2 % MOD ;
    }
    else if( m == n )
    {
        bool flag = true ;
        for( int i = 1 ; i <= n ; i++ )
        {
            if( !s[i] )
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            long long ans = 1 ;
            for( int i = 1 ; i <= n ; i++ )ans = ans * i % MOD ;
            cout << ans % MOD ;
        }
        else{
            cout << 0 ;
        }
    }
    else if( m == 1 )
    {
        for( int i = 1 ; i <= n ; i++ )
        {
            if( s[i] )
            {
                int cnt = 0 ;
                for( int j = 1 ; j <= n ; j++ )
                {
                    if( c[j] > i - 1 )cnt++;
                }
                long long ans = 1 ;
                for( int i = 1 ; i < n ; i++ )ans = ans * i % MOD ;
                cout << ans * cnt % MOD ;

            }
        }
    }
    else
    {

        ans = 0 ;
        dfs(1);
        cout <<ans ;
    }

    return 0 ;
}
