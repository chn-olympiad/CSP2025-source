#include <iostream>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    frepoen("number.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    if(n==1&&m==1)
    {
        cout<<1;
        return 0;
    }
    return 0;
}
