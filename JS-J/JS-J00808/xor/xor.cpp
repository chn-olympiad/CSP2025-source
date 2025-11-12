#include <iostream>
using namespace std;
const int N = 5e5;
int read()
{
    int res = 0;
    char ch = getchar();
    while (isdigit(ch) == false)
        ch = getchar();
    while (isdigit(ch) == true)
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res;
}
int a[N + 5];
int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    int n = read() , k = read();
    for (int i = 1 ; i <= n ; ++i)
        a[i] = read();
    int tot = 0 , now = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        int dp = 0;
        for (int j = i ; j > now ; --j)
        {
            if (i == j) dp = a[i];
            else dp ^= a[j];
            if (dp == k)
            {
                ++tot , now = i;
                break;
            }
        }
    }
    cout << tot << endl;
    fclose(stdin);
    fclose(stdout);
}

