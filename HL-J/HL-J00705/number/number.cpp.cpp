
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n;
    cin >> n;
    else
    {
        if(n<10)
        {
            cout << n;
        }
        else if(n<100)
        {
            if(n%10*10+n/10 > n)
            {
                cout << n%10*10+n/10;
            }
            else
            {
                cout << n;
            }
        }
        else
        {
        	cout << n;
		}
    }
    return 0;
}
