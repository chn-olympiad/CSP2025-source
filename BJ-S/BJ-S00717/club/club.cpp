#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 20 , maxm = 2e4 + 20;
long long int t , n , a[maxn][4] , ans , cnt[4] , now[maxn];

int main()
{
    freopen( "club.in" , "r" , stdin );
    freopen( "club.out" , "w" , stdout );
    cin >> t;
    for( int m = 1 ; m <= t ; ++m )
    {
        ans = 0 ;
        for( int i = 1 ; i <= 3 ; ++i )
            cnt[i] = 0;
        cin >> n;
        for( int i = 1 ; i <= n ; ++i )
        {
            now[i] = 0;
            int tmp = 0;
            int tmp_mx = -maxm , tmp_mx_place , tmp_mx_place_to;
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            for( int j = 1 ; j <= 3 ; ++j )
            {
                if( cnt[j] < n / 2 && tmp < a[i][j] )
                {
                    tmp = a[i][j];
                    now[i] = j;
                }
                if( cnt[j] >= n / 2 )
                {
                    for( int k = 1 ; k < i ; ++k )
                    {
                        if( now[k] != j )
                            continue;
                        for( int l = 1 ; l <= 3 ; ++l )
                        {
                            if( l == now[k] )
                                continue;
                            if( a[k][l] - a[k][now[k]] > tmp_mx )
                            {
                                tmp_mx = a[k][l] - a[k][now[k]];
                                tmp_mx_place = k;
                                tmp_mx_place_to = l;
                            }
                        }
                    }
                    if( a[i][j] + tmp_mx > tmp )
                    {
                        tmp = a[i][j] + tmp_mx;
                        now[i] = j;
                    }
                }
            }
            if( tmp_mx != -maxm && now[i] == now[tmp_mx_place] )
                now[tmp_mx_place] = tmp_mx_place_to;
            if( cnt[now[i]] < n / 2 )
                cnt[now[i]]++;
            ans += tmp;
        }
        cout << ans << endl;
    }
    return 0;
}
