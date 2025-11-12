#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<3) 
    {
        cout<<0;
        return 0;
    }
    else if(n==3)
    {
        int x=max(max(a[1],a[2]),a[3]);
        sum=a[1]+a[2]+a[3];
        if(sum>2*x)
        {
            cout<<1;
            return 0;
        }
        else 
        {
            cout<<0;
            return 0;
        }
    }

    return 0;
}