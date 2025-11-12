#include <iostream>
using namespace std;
long long cnt;
int a[10000],n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.in","w",stdout);
    cin>>n;
    for(int i = 0;i<=n;i++)
    {
        cin>>a[n];
    }

    for(int j = 0;j<=n;j++)
    {
        cout<<a[n];
    }
    return 0;
}
