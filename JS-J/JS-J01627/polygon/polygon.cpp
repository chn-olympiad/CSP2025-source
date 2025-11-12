#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=0;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(a[1]+a[2]>3)
            cout<<1;
        else
            cout<<0;
    }
    if(n==4)
    {
        if(a[1]+a[2]>a[3])
            cnt++;
        if(a[1]+a[2]>a[4])
            cnt++;
        if(a[1]+a[3]>a[4])
            cnt++;
        if(a[2]+a[3]>a[4])
            cnt++;
        if(a[1]+a[2]+a[3]>a[4])
            cnt++;
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
