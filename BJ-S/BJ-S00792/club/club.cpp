#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int v, w;
}a[100010], b[100010], c[100010];
int i1, i2, i3, cnt1, cnt2, T, n, cnt, ans;
bool cmp( Node x, Node y )
{
    return x.v > y.v;
}
bool pk( int aa, int bb )
{
    if( aa == 1 && bb == 2 )
    {
        int cnt1 = i1, cnt2 = i2;
        while( true )
        {
            if( a[cnt1].w == b[cnt2].w ) cnt1++, cnt2++;
            else if( a[cnt1].w > b[cnt2].w ) return 0;
            else return 1;
        }
    }
    if( aa == 3 && bb == 2 )
    {
        int cnt1 = i2, cnt2 = i3;
        while( true )
        {
            if( b[cnt1].w == c[cnt2].w ) cnt1++, cnt2++;
            else if( b[cnt1].w > c[cnt2].w ) return 0;
            else return 1;
        }
    }
    if( aa == 1 && bb == 3 )
    {
        int cnt1 = i1, cnt2 = i3;
        while( true )
        {
            if( a[cnt1].w == c[cnt2].w ) cnt1++, cnt2++;
            else if( a[cnt1].w > c[cnt2].w ) return 0;
            else return 1;
        }
    }
}
int main()
{
    freopen( "club.in", "r", stdin );
    freopen( "club.out", "w", stdout );
    cin >> T;
    while( T-- )
    {
        ans = 0;
        cin >> n;
        for( int i = 1; i <= n; i++ )
        {
            cin >> a[i].v >> b[i].v >> c[i].v;
            a[i].w = b[i].w = c[i].w = i;
        }
        sort( a + 1, a + n + 1, cmp );
        sort( b + 1, b + n + 1, cmp );
        sort( c + 1, c + n + 1, cmp );
        for( int i = 1; i <= n / 2; i++ )
        {
            if( a[i1].w == b[i2].w )
            {
                if( pk( 1, 2 ) ) ans = ans + a[i1].v + b[++i2].v;
                else ans = ans + a[++i1].v + b[i2].v;
                ans += c[i3].v;
                i1++, i2++, i3++;
            }
            else if( a[i1].w == c[i3].w )
            {
                if( pk( 1, 3 ) ) ans = ans + a[i1].v + c[++i3].v;
                else ans = ans + a[++i1].v + c[i3].v;
                ans += b[i2].v;
                i1++, i2++, i3++;
            }
            else if( c[i3].w == b[i2].w )
            {
                if( pk( 3, 2 ) ) ans = ans + c[i3].v + b[++i2].v;
                else ans = ans + c[++i3].v + b[i2].v;
                ans += a[i1].v;
                i1++, i2++, i3++;
            }
            else
            {
                ans += a[i1].v + b[i2].v + c[i3].v;
                i1++, i2++, i3++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}