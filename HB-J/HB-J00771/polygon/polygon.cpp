#include <bits/stdc++.h>
using namespace std;
int a[1000000],mod=998244353,cnt=0,sum=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("polyqon.in","r",stdin);
    freopen("polyqon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<=1)
        {
            cout<<0;
            return 0;
        }
        sum+=a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[2]+a[3]>a[1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
