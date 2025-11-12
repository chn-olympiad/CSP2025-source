#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,a[10001],s=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
        s+=a[i];

    }
    if(k==0)
    {
        cout<<"1";
    }
    if(k==2)
    {
        cout<<k;
    }
    else
    {
        cout<<k-1;
    }


    return 0;
}
