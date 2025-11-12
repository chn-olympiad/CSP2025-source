#include <iostream>
#include <algorithm>
using namespace std;
long long g[1005];
bool cmp(long long x,long long y)
{
    return x > y;
}
int main()
{
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
        long long n,m;
        cin >> n >> m;
        for(long long i = 1 ; i <= n * m ; i++) cin >> g[i];
        long long data = g[1];
        sort(g+1,g+n*m+1,cmp);
        long long id;
        for(int i = 1 ; i <= n * m ; i++)
        {
            if(g[i] == data)
            {
                id = i;
                break;
            }
        } 
        long long lie = (id - 1) / n + 1;
        long long heng = id - ((lie - 1) * n + 1) + 1;
        if(lie % 2 == 0) heng = n - heng + 1;
        cout << lie << " " << heng << endl; 
        return 0;
}
