#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    int a[n];
    long long s=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long su;
    for(int i=0;i<n;i++)
    {
        su=a[i];
        for(int j=i+1;j<n;j++)
        {
            su+=a[j];
            if(j!=1&&su>j*2)
            {
                s++;
            }
        }
    }
    cout<<s;
    return 0;
}
