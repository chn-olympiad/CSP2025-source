#include <bits/stdc++.h>
#include <bits/c++config.h>
#include <bits/memoryfwd.h>
using namespace std;
int n,k,a[1048580],m,z,s=0;
int h(int x,int y)
{
    return x^y;

}
int main()
{
    freopen ("xor.in"," r",stdin);
    freopen ("xor.out"," w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    m=n;
    for(int i=1;i<=n;i++)
    {
        z=a[i];
        for(int j=1;j<=m-1;j++)
        {

            z=h(z,a[j]);
        }
        if(z==k)
        {
            s++;

        }
    }
    cout<<(s+1);
    return 0;

}
