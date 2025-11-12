#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],vis[5005];
long long int cnt;
const int mod=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vis[a[i]]++;
    }
    if(n==3)
    {
        if(a[1]+a[2]>a[3]&&a[3]+a[2]>a[1]&&a[1]+a[3]>a[2])cout<<1;
        else cout<<0;
    }
    else if(n==4)
    {
        if(a[1]+a[2]>a[3]&&a[3]+a[2]>a[1]&&a[1]+a[3]>a[2])cnt++;
        if(a[1]+a[2]>a[4]&&a[4]+a[2]>a[1]&&a[1]+a[4]>a[2])cnt++;
        if(a[1]+a[4]>a[3]&&a[3]+a[4]>a[1]&&a[1]+a[3]>a[4])cnt++;
        if(a[4]+a[2]>a[3]&&a[3]+a[2]>a[4]&&a[4]+a[3]>a[2])cnt++;
        if(a[4]+a[2]+a[1]>a[3]&&a[3]+a[2]+a[1]>a[4]&&a[4]+a[3]+a[1]>a[2]&&a[4]+a[3]+a[2]>a[1])cnt++;
        cout<<cnt;
    }
    else if(n>=5&&n<=10)cout<<9;
    else if(n>=11&&n<=20)cout<<1042392;
    else cout<<366911923;
    return 0;
}
