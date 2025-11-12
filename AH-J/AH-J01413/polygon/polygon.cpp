#include<bits/stdc+++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int s=0;
    int a[5005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        if(a[i-1]+a[i-2]>a[i])
        {
            s++;
        }
    }
    cout<<s;
    return 0;
}
