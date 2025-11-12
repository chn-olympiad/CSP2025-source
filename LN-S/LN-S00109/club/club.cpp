#include<bits/stdc++.h>
using namespace std;

struct number
{
    int a , b , c;

    bool operator < (number &w) const
    {
            return a < w.a;
            return b < w.b;
            return c < w.c;
    }

};

int t;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        int n ;
        cin >> n;

        struct number q[n];
        for(int i = 0 ; i < n ;i ++) cin >> q[i].a >> q[i].b >> q[i].c;

        sort(q , q + n);

        long long sum = 0;
        long long sum_a = 0 , sum_b = 0 , sum_c = 0;

        for(int i = 0 ; i < n ; i++)
        {
            int tmp = max({ q[i].a , q[i].b , q[i].c });

            cout << tmp << ' ' << sum << endl;
            if( tmp == q[i].a )
            {
                if( sum_a < n/2 )
                    sum_a ++;
                else
                    q[i].a = 0;
            }

            if( tmp == q[i].b )
            {
                if( sum_b < n/2 )
                    sum_b ++;
                else
                    q[i].b = 0;
            }

            if( tmp == q[i].c )
            {
                if( sum_c < n/2 )
                    sum_c ++;
                else
                    q[i].c = 0;
            }

            sum += max({ q[i].a , q[i].b , q[i].c });
        }

        cout << sum << endl;
    }
    return 0;
}
