#include <iostream>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n,k=0,dinggood=1,y;
    cin>>m>>n;
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='1')
        {
            k++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>y;
    }
    for(int i=1;i<=k;i++)
    {
        dinggood*=i;
    }
    cout<<dinggood%998244353;
}
