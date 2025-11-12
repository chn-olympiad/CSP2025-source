#include<bits/stdc++.h>
using namespace std;
int n,a[5010],vis[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)
    {
        cout<<"0";
        return 0;
    }
    if(n==3)
    {
        int l1,l2,l3,sum,sum1;
        cin>>l1>>l2>>l3;
        sum=l1+l2+l3;
        sum1=max(max(l1,l2),l3);
        if(sum>sum1*2)
        {
            cout<<1;return 0;
        }
        else cout<<"0";return 0;
    }

    return 0;
}