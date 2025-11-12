#include <bits/stdc++.h>

using namespace std;
int n , m ,st;
vector<int> v;
int main()
{
    freopen("seat.in","r",stdin );
    freopen("seat.out" , "w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n*m ; i++ )
    {
        int a;
        cin >> a;
        if(i == 0)
        {
            st = a;
        }
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int hang = 0 , lie = 1;
    for (int i = v.size() - 1 ; i >= 0 ;i-- )
    {
        if ( lie % 2 == 1)
        {
            hang++;
        }
        else hang--;

        if(hang > n )
        {
            lie++;
            hang = n;
        }
        if(hang < 1)
        {
            lie++;
            hang = 1;
        }
        if (v[i] == st )
        {
            cout << lie << ' ' << hang << endl;
            // return 0;
        }
    }
    return 0;
}

// 3 3 94 95 96 97 98 99 100 93 92
