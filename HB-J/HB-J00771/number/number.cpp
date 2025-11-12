#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s;
    cin>>s;
    while(s!=0)
    {
        int b=s%10;
        s/=10;
        cout<<b;
    }
    return 0;
}
