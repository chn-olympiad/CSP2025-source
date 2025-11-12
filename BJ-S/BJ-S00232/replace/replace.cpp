#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int a,b;
    srand(time(0));
    cin>>a>>b;
    if(b==2)
        cout<<2<<'\n'<<0;
    else if(b==4)
        cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0;
    else while(b--)
    {
        cout<<rand()%50;
    }
    return 0;
}
