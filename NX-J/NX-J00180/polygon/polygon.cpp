#include<iostream>
#include<algorithm>
using namespace std;

int n;
int main()
{
    freopen("polygon.in","r",stdin);

    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3)
    {
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]>a[2]) cout<<1;
        else cout<<0;
    }
    return 0;
}
