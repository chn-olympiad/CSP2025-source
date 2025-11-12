#include<bits/stdc++.h>

using namespace std;

void init()
{
    freopen( "replace.in" , "r" , stdin );
    freopen( "replace.out" , "w" , stdout );
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n , q;
string s1[200010] , s2[200010];

int main()
{
    init();
    cin >> n >> q;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> s1[i] >> s2[i];
    while ( q-- )
    {
        string t1 , t2;
        int ans = 0;
        cin >> t1 >> t2;
        for ( int i = 1 ; i <= n ; i++ )
            for ( int j = 0 ; j < t1.size() - s1[i].size() + 1 ; j++ )
                for ( int k = 0 ; k < s1[i].size() ; k++ )
                    if ( t1[j + k] != s1[i][k] ) break;
                    else if ( k == s1[i].size() - 1 )
                    {
                        string tmp = t1;
                        for ( int l = j ; l <= j + k ; l++ )
                            tmp[l] = s2[i][l - j];
                        if ( tmp == t2 ) ans++;
                    }
        cout << ans << endl;
    }
    return 0;
}
