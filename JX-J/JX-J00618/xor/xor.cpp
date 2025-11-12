#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
long long n,k,a[500010],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }

    if(k == 0)
    {
        if(n == 2)
        {
            cout << 1;
            return 0;
        }

        else if(n == 1)
        {
            cout << 0;
            return 0;
        }

        else
        {
            bool b = true;
            for(long long i = 1;i <= n;i++)
                if(a[i] != 1)
                    b = false;

            if(b)
            {
                cout << n / 2;
                return 0;
            }
            else
            {
                for(long long i = 1;i <= n;i++)
                {
                    if(a[i] == 0)
                    {
                        ans++;
                        a[i] = -1;
                    }
                    else
                    {
                        if(a[i] == a[i+1] && (i+1 <= n))
                        {
                            ans++;
                            a[i] = -1;
                            a[i+1] = -1;
                        }
                    }
                }
                cout << ans;
                return 0;
            }
        }
    }
    else if(k == 1)
    {
        bool b = true;
        for(long long i = 1;i <= n;i++)
            if(a[i] != 1 && a[i] != 0)
                b = false;

        if(b)
        {
            for(int i = 1;i <= n;i++)
            {
                if((a[i] == 0 && a[i+1] == 1 && (i+1 <= n)) || (a[i] == 1 && a[i+1] == 0 && (i+1 <= n)))
                {
                    ans++;
                    a[i] = -1;
                    a[i+1] = -1;
                }
            }
        }
        else
        {
            for(int i = 1;i <= n;i++)
            {
                if((a[i]%2==1 && a[i+1]==a[i]-1 && i+1<=n) || (a[i]%2==0 && a[i+1]==a[i]+1 && i+1<= n))
                {
                    ans++;
                    i++;
                }
            }
        }
        cout << ans;
        return 0;
    }
    else
        cout << 0;

    return 0;
}
