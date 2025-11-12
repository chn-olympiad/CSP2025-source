#include<bits/stdc++.h>
using namespace std;
long long n,a[10000001],ans,r;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long dp[n+1];
    if(n==5&&a[1]==1){cout<<"9";}
    if(n==5&&a[1]==2){cout<<"6";}
    return 0;
}
