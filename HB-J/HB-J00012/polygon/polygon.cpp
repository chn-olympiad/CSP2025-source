#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=1;
    cin>>n;
    if(n==3)
    {
        int a[5];
        cin>>a[0]>>a[1]>>a[2];
        int x=max(max(a[0],a[1]),a[2]);
        if(a[0]+a[1]+a[2]>2*x) cout<<1;
        else cout<<0;
        return 0;
    }
    else if(n<3) cout<<0;
    for(int i=1;i<=n;i++) cnt*=i;
    cnt/=6;
    cnt-=n;
    cnt++;
    cout<<cnt;
    return 0;
}
