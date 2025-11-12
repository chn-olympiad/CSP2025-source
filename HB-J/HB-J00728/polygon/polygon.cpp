#include <iostream>
using namespace std;
int main()
{
    //freopen("polygon.in" , "w" , stdin);
    //freopen("polygon.out" , "r" , stdout);
    int n , a[5000];
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    cout << a[4] + a[5];
    return 0;
}
