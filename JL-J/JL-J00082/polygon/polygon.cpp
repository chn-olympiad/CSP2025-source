#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int x=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x+=a[i];
    }
    sort(a+1,a+1+n);
    if(a[1]*2>=x&&n==3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        cout<<1;
        return 0;
    }
}
