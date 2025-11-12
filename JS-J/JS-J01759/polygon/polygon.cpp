#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int ans,sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    sort(a+1,a+n+1);
    sum=a[1]+a[2];
    if(ans==n)
    {
        cout<<n-2;
    }else{
        if(sum>a[3])
        {
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
