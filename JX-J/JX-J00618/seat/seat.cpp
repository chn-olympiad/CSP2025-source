#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
long long a[20][20],b[10010];
long long n,m,f,k=1,h = 1,l = 1;
bool cmp(long long x,long long y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(long long i = 1;i <= n * m;i++)
        cin >> b[i];

    f = b[1];

    if(f == 100){
        cout << 1 << " " << 1;
        return 0;
    }

    sort(b+1,b+n*m+1,cmp);
    long long h = 1,l = 1;
    while(k <= n * m)
    {
        a[h][l] = b[k];
        k++;
        if(l&1)
        {
            if((h + 1) <= n)
                h++;
            else
                l++;
        }
        else
        {
            if((h - 1) > 0)
                h--;
            else
                l++;
        }
    }

    for(long long i = 1;i <= n;i++)
    {
        for(long long j = 1;j <= m;j++)
        {
            if(a[i][j] == f)
            {
                cout << j << " " << i;
                return 0;
            }
        }
    }

    return 0;
}
