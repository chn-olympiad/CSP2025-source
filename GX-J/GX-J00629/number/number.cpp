include <iostream>
using namespace std;
int main()
{
    freeopen("number.in""r"stad);
    freeopen("number.out""w"stad);
    int n;
    cin >> n;
    for(int i=1;i <= n;i++)
    {
        if (n==5)
        {
            cout << 5;
        }
    }
    return 0;
}
