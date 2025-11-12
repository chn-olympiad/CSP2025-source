#include <iostream>
#include <algorithm>
using namespace std;

int a[110];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    int point = a[1];
    sort(a + 1,a + n * m + 1);
    int num;
    for(int i = n * m;i >= 1;i--)
    {
        if(a[i] == point)
        {
            num = n * m - i + 1;
            break;
        }
    }
    int nn,mm;
    if(num % n == 0) mm = num / n;
    else mm = num / n + 1;
    nn = num % m;
    if(mm % 2 == 0) nn = n - nn + 1;
    if(nn == 0) nn = n;
    cout << mm << " " <<  nn;
    return 0;
}
