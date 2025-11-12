#include<bits/stdc++.h>
using namespace std;
string str[200005][3], t1, t2;
int Find( string x, string y )
{
    int j, k, t;
    for( j = 0; j < x.length(); j++ )
    {
        if( x[j] == y[0] )
        {
            t = 0;
//            cout << j << "#" << endl;
            for( k = 1; k < y.length(); k++ )
            {
                if( x[j+k] != y[k] )
                {
//                    cout << k << "%" << endl;
                    t = 1;
                    break;
                }
            }
            if( !t )
            {
//                cout << "*" << endl;
                return j;
            }
        }
    }
    return -1;
}
int main()
{
    freopen( "replace.in", "r", stdin );
    freopen( "replace.out", "w", stdout );
    int n, q, i, pos, cnt = 0;
    cin >> n >> q;
    for( i = 1; i <= n; i++ )
    {
        cin >> str[i][1] >> str[i][2];
    }
    while(q--)
    {
        cnt = 0;
        cin >> t1 >> t2;
        for( i = 1; i <= n; i++ )
        {
            pos = Find(t1, str[i][1]);
//            cout << pos << endl;
            if( pos == -1 )
                continue;
            string x, z, h;
            for( int j = 0; j < pos; j++ )
            {
                x = x + t1[j];
            }
            for( int j = pos + str[i][1].length(); j < t1.length(); j++ )
            {
                z = z+ t1[j];
            }
            h = x + str[i][2] + z;
//            cout << x << endl;
//            cout << z << endl;
            if( t2 == h )
                cnt++;
        }
        cout << cnt << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
