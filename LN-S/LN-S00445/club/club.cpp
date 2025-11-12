#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,d=0,e = 0;
    cin >>t;
    for(int i = 1;i <= t;i++)
    {
        long long n;
        cin >> n;
        for(int j = 1; j<= n;j++)
        {
            long long a,b,c;
            cin >> a >> b >> c;
            if(a>b&&a>c)
            {
                d=a;

            }
            if(b>a&&b>c)
            {
                d=b;
            }
            if(c>a&&c>b)
            {
                d=c;
            }
            e=e+d;
            e=e;
        }

        cout << e << endl;
        e=0;
        d = 0;

    }


    return 0;
}



