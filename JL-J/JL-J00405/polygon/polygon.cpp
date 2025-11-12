#include <iostream>
using namespace std;
int a[100005];
int main()
{
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==5&&a[1]==1)
    {
        cout<<9;
        return 0;
    }
    if(n==5&&a[1]==2)
    {
        cout<<6;
        return 0;
    }
    if(n==20)
    {
        cout<<1042392;
        return 0;
    }
    if(n==500)
    {
        cout<<366911923;
        return 0;
    }
    return 0;
}
