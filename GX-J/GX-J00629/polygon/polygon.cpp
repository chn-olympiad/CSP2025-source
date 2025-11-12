#include <iostream>
using namespace std;
int main()
{
    freeopen("polygon.in""r"stad);
    freeopen("polygon.out""w"stad);
    int n,a[105],num = 0;
    cin >> n;
    for(int i=1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i <= n;i++)
    {
        if (a[i]+ a[i+1]+ a[i+2] > a[i+2]*2)
        {
            num++;
        }
        if (a[i] + a[i+1] + a[i+2] + a[i+3] > a[i+3])
        {
            num++;
        }
    }
    cout << num;
    return 0;
}
