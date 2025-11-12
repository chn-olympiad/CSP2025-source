#include<bits/stdc++.h>
using namespace std;
int a[200005][5], m[200005][5], n, ans = 0, sum = 0, c[3];
struct node
{
    int id, sc;
};
bool cmp( node a, node b )
{
    return a.sc > b.sc;
}
node b1[200005], b2[200005], b3[200005];
void dfs( int state )
{
//    if( ans != 0 )
//        return;
    if( state == n+1 )
    {
        if( sum > ans )
            ans = sum;
        return;
    }
    if( c[m[state][1]] < n/2 )
    {
        sum += a[state][m[state][1]];
        c[m[state][1]]++;
        dfs(state+1);
        sum -=a[state][m[state][1]];
        c[m[state][1]]--;
    }
    if( c[m[state][2]] < n/2 )
    {
        sum += a[state][m[state][2]];
        c[m[state][2]]++;
        dfs(state+1);
        sum -=a[state][m[state][2]];
        c[m[state][2]]--;
    }
    if( c[m[state][3]] < n/2 )
    {
        sum += a[state][m[state][3]];
        c[m[state][3]]++;
        dfs(state+1);
        sum -=a[state][m[state][3]];
        c[m[state][3]]--;
    }
    return;
}
int main()
{
    freopen( "club.in", "r", stdin );
    freopen( "club.out", "w", stdout );
    int t, i, m1 = 0, m2 = 0, a0, j;
    cin >> t;
    while(t--)
    {
        cin >> n;
        a0 = 0;
        sum = ans = 0;
        c[1] = c[2] = c[3] = 0;
/*        int b[5] = {0};
        for( i = 1; i <= n; i++ )
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if( a[i][1] > a[i][2] )
                m1 = 1;
            else
                m1 = 2;
            if( a[i][m1] < a[i][3] )
            {
                m2 = m1;
                m1 = 3;
            }
            else
            {
                if( a[i][3-m1] > a[i][3] )
                    m2 = 3-m1;
                else
                    m2 = 3;
            }
            m[i][1] = m1;
            m[i][2] = m2;
            m[i][3] = 6-m1-m2;
            sum += a[i][m1];
            b[m1]++;
        }
        if( b[1] <= n/2 && b[2] <= n/2 && b[3] <= n/2 )
        {
            cout << sum << endl;
            continue;
        }
//        cout << sum << endl;
*/
        for( i = 1; i <= n; i++ )
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if( a[i][2] == 0 && a[i][3] == 0 )
            {
                a0++;
                b1[i] = {i, a[i][1]};
            }
//            b2[i] = {i, a[i][2]};
//            b3[i] = {i, a[i][3]};
            if( a[i][1] > a[i][2] )
                m1 = 1;
            else
                m1 = 2;
            if( a[i][m1] < a[i][3] )
            {
                m2 = m1;
                m1 = 3;
            }
            else
            {
                if( a[i][3-m1] > a[i][3] )
                    m2 = 3-m1;
                else
                    m2 = 3;
            }
            m[i][1] = m1;
            m[i][2] = m2;
            m[i][3] = 6-m1-m2;

        }
//        sort( b2+1, b2+n+1, cmp );
//        sort( b3+1, b3+n+1, cmp );
/*        for( i = 1; i <= n; i++ )
        {
            for( j = 1; j <= 3; j++ )
                cout << m[i][j] << " ";
            cout << endl;
        }
*/        if( a0 == n )
        {
            sort( b1+1, b1+n+1, cmp );
            for( i = 1; i <= n/2; i++ )
                sum += b1[i].sc;
            cout << sum << endl;
        }
        else
        {
            dfs(1);
            cout << ans << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
