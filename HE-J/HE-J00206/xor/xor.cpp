#include <bits/stdc++.h>
using namespace std;
int a[500010] , q[500010] , vis[500010][500010];
int main()
{
    int n , k , cnt = 1;
    cin >n >>k;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >>a[i];
        q[i] = q[i-1] ^ a[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i] == k)
        {
            vis[i] = 1;
            cnt++;
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(q[i] ^ q[j] == k)
           {
               vis[cnt][i] = 1;
               vis[cnt][j] = 1;
               cnt++;
           }
        }
    }

    return 0;
}
