#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a[105];
    cin>>n;
    int r;
    cin>>r;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
         cout<<a[i];
    }
}
