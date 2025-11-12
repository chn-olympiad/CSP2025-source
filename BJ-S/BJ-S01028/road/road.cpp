#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define maxn 1000007

using namespace std;

struct node{
    int x , y; ll w;
}a[maxn];

ll n , m , K , tot , ans , fa[maxn] , c[maxn] , pos[maxn]; vector< node >v[20];

ll find( ll s1 )
{

    return ( fa[s1] == s1 ? s1 : fa[s1] = find( fa[s1] ) );
}

void merge( ll s1 , ll s2 )
{
    fa[find( s1 )] = find( s2 );
}

bool cmp( ll s1 , ll s2 )
{
    return a[s1].w < a[s2].w;
}

bool cmp2( node s1 , node s2 )
{
    return s1.w < s2.w;
}

int main()
{
    freopen( "road.in" ,"r" , stdin );
    freopen( "road.out" ,"w" , stdout );
    ios ::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> n >>m >> K;
    ans = 1145141145141145140; //n = 10000; K = 10; m = 1000000;
    for( int i = 1 ; i <= n ; ++i ) fa[i] = i;
    for( int i = 1 ;i <= m ; ++i ) {
        cin >> a[i].x >> a[i].y >> a[i].w;
        pos[i] = i;
    }
    sort( a + 1 , a + m+ 1 , cmp2 );
   // for( int i = 1 ;i<=m ; ++i ) a2[i] = a[pos[i]];
    //for( int i = 1 ;i <= m ; ++i ) a[i] = a2[i];
    for( int i = 1 ; i <= m ; ++i ) {
        if(  find( a[i].x ) != find( a[i].y ) ) {
            a[++tot]= a[i];
            merge( a[i].x , a[i].y );
          //  cout <<i <<"kkk";
        }
    }
    m = tot;
    for( int i = 1 ; i <= K ; ++i ) {
            cin>>c[i];

        for( int j = 1 ;j <= n ; ++j ) {
            node s1; s1.x = n + i; s1.y = j;  cin >> s1.w;
            a[++m]= s1;
        }
    }
    sort( a + 1 , a + m + 1 , cmp2 );
    for( int i = 0 ; i < ( 1 << K ) ; ++i ) {
        for( int j = 1 ; j<= n + K ; ++j ) fa[j] = j;
        ll sum = 0 , ppp = n - 1;
    for( int j = 0 ; j < K ; ++j )
        if( i & ( 1 <<j ) ) {sum += c[j + 1]; ppp ++; }
        ll s = 0;
        for( int j = 1 ; j<= m ; ++j )
            if( ( a[j].x <= n ) || ( i & ( 1 << ( a[j].x - n - 1 ) ) ) ) {
                if( find( a[j].x ) != find( a[j].y ) ) {
                    sum += a[j].w; merge( a[j].x , a[j].y );
                    s ++;
                    if( s == ppp ) {
                        break;
                    }
                }
            }
        ans = min( ans , sum );
    }
    cout << ans <<"\n";
    return 0;
}
