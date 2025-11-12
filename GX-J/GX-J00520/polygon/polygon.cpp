#include <iostream>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b<c||a+c<b||a+c<b)
    {
        b=0;
    }
    else
    {
        b=1;
    }
    cout << b<< endl;
    return 0;
}
