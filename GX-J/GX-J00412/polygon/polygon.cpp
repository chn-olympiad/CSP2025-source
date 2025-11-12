#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    int a[5111];
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1;a+1+n);
    for(int i=1;i<=n*n;i++)
    {
        if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+i]>=a[n])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
