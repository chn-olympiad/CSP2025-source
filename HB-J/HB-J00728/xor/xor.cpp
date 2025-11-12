#include <iostream>
using namespace std;
int main()
{
      freopen("xor.in" , "w" , stdin);
    freopen("xor.out" , "r" , stdout);
    int n , k , a[2^20];
    cin >> n >> k;
    for (int i =  1; i <+ n ; i++)
    {
        cin >> a[i];
    }
    cout << a[1];
    return 0;
}
