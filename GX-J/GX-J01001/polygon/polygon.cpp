#include<bits/stdc++.h>
using namespace std;
bool px(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005],ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,px);
    if(n==3)
    {
        if((a[1]+a[2]+a[3])/2>max(a[1],a[2]))
        {
           ans++;
        }
    }
    cout<<ans;
    return 0;
}
