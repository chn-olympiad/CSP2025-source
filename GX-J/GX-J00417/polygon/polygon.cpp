#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,a[5001];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    else if(n==4)
    {
        long long ans=0;
        if(a[1]+a[2]>a[3])ans++;
        if(a[1]+a[2]>a[4])ans++;
        if(a[1]+a[3]>a[4])ans++;
        if(a[3]+a[2]>a[4])ans++;
        if(a[1]+a[2]+a[3]>a[4])ans++;
        cout<<ans;return 0;
    }
    else if(n==5)
    {
        long long ans=0;
        if(a[1]+a[2]>a[3])ans++;
        if(a[1]+a[2]>a[4])ans++;
        if(a[1]+a[2]>a[5])ans++;
        if(a[1]+a[3]>a[4])ans++;
        if(a[1]+a[3]>a[5])ans++;
        if(a[1]+a[4]>a[5])ans++;
        if(a[1]+a[4]>a[5])ans++;
        if(a[2]+a[3]>a[4])ans++;
        if(a[2]+a[3]>a[5])ans++;
        if(a[2]+a[4]>a[5])ans++;
        if(a[3]+a[4]>a[5])ans++;
        if(a[1]+a[2]+a[3]>a[4])ans++;
        if(a[1]+a[2]+a[3]>a[5])ans++;
        if(a[1]+a[2]+a[4]>a[5])ans++;
        if(a[1]+a[3]+a[4]>a[5])ans++;
        if(a[2]+a[3]+a[4]>a[5])ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[5])ans++;
        cout<<ans;return 0;
    }
    else if(n==6)
    {
        long long ans=0;
        if(a[1]+a[2]>a[3])ans++;
        if(a[1]+a[2]>a[4])ans++;
        if(a[1]+a[2]>a[5])ans++;
        if(a[1]+a[2]>a[6])ans++;
        if(a[1]+a[3]>a[4])ans++;
        if(a[1]+a[3]>a[5])ans++;
        if(a[1]+a[3]>a[6])ans++;
        if(a[1]+a[4]>a[5])ans++;
        if(a[1]+a[4]>a[6])ans++;
        if(a[1]+a[5]>a[6])ans++;
        if(a[2]+a[3]>a[4])ans++;
        if(a[2]+a[3]>a[5])ans++;
        if(a[2]+a[3]>a[6])ans++;
        if(a[2]+a[4]>a[5])ans++;
        if(a[2]+a[4]>a[6])ans++;
        if(a[2]+a[5]>a[6])ans++;
        if(a[3]+a[4]>a[5])ans++;
        if(a[3]+a[4]>a[6])ans++;
        if(a[3]+a[5]>a[6])ans++;
        if(a[4]+a[5]>a[6])ans++;
        if(a[1]+a[2]+a[3]>a[4])ans++;
        if(a[1]+a[2]+a[3]>a[5])ans++;
        if(a[1]+a[2]+a[3]>a[6])ans++;
        if(a[1]+a[2]+a[4]>a[5])ans++;
        if(a[1]+a[2]+a[4]>a[6])ans++;
        if(a[1]+a[2]+a[5]>a[6])ans++;
        if(a[1]+a[3]+a[4]>a[5])ans++;
        if(a[1]+a[3]+a[4]>a[6])ans++;
        if(a[1]+a[3]+a[5]>a[6])ans++;
        if(a[1]+a[4]+a[5]>a[6])ans++;
        if(a[2]+a[3]+a[4]>a[5])ans++;
        if(a[2]+a[3]+a[4]>a[6])ans++;
        if(a[2]+a[3]+a[5]>a[6])ans++;
        if(a[2]+a[4]+a[5]>a[6])ans++;
        if(a[3]+a[4]+a[5]>a[6])ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[5])ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[6])ans++;
        if(a[1]+a[2]+a[3]+a[5]>a[6])ans++;
        if(a[1]+a[2]+a[4]+a[5]>a[6])ans++;
        if(a[1]+a[3]+a[4]+a[5]>a[6])ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6])ans++;
        cout<<ans;return 0;
    }
    return 0;
}
