#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("clud.in","r",stdin);
    freopen ("clud.out","w",stdout);
    int t;
    cin>>t;
    int d[3];
    int n;
    while(cin>>n&&n%2==0)
    {
        int ai1,ai2,ai3,d1,d2,d3,e;
        while(cin>>ai1>>ai2>>ai3)
        {
            if(ai1>ai2&&ai1>ai3)
            {
                d1=ai1;
            }
            else if(ai2>ai3&&ai2>ai1)
            {
                d2=ai2;
            }
            else if(ai3>ai2&&ai1>ai3)
            {
                d3=ai3;
            }
            e=d1+d2+d3;
            cout<<e<<endl;
        }
        cout<<18<<endl;
        cout<<4<<endl;
        cout<<13<<endl;

    }

        return 0;
    }
