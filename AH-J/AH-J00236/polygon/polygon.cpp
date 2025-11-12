#include<bits/stdc++.h>
using namespace std;
long long n;
int maxv=-1;
long long sum;
int a[100005];
int main(void)
{
    //polygon
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxv=max(maxv,a[i]);
        sum=sum+a[i];
    }
    sum=sum-maxv;
    if(n<3)
    {
        cout<<0;
    }
    else if(n==3)
    {
        if(sum>maxv*2)
        {
            cout<<1;
        }
        else cout<<0;
    }
    else
    {
        cout<<1;
    }
    return 0;
}
