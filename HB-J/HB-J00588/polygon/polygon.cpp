#include<bits/stdc++.h>
using namespace std;

int a[5005];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s = 0;
    long long ans = 0;

    cin>>n;

    if(n = 3)
    {
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+1+n);

        if(a[1] + a[2] > a[3])
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
