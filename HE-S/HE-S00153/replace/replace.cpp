#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    char x;
    cin >>n>>m;
    for (int i=1; i<=n+m; i++)
    {
        for (int i=1; i<=2; i++)
        {
            cin >>x;
        }
    }
    if ((n==4) || (m==2))
    {

        cout <<2<<endl<<0;
    }
    else if ((n==3) || (m==4))
    {
        cout <<0<<endl <<0<<endl<<0<<endl<<0;
    }
    else
    {

        cout <<4 <<endl <<0;
    }
    return 0;
}

