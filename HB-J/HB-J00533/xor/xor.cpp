#include <iostream>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,z=0,a,d=0,s;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>s;
        if(z<k)
        {
            z+=s;
        }
        else if(z>k)
        {
            z-=s;
        }
        if(s==k)
        {
            d++;
            z=0;
        }
        if(z==k)
        {
            z=0;
            d++;
        }
    }
    cout<<d;
    return 0;
}
