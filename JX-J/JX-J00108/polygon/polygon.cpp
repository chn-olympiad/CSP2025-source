#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]+a[i+1]>a[i+2]&&a[i]-a[i+1]<a[i+2])
            ans++;
        if(n>=4)
            if(a[i]+a[i+1]+a[i+2]+a[i+3]>max(a[i],a[i+1])&&a[i]+a[i+1]+a[i+2]+a[i+3]>max(a[i+2],a[i+3]))
                ans++;
        if(n>=5)
            if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>max(a[i],a[i+1])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>max(a[i+2],a[i+3])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>max(a[i+3],a[i+4]))
                ans++;
        if(n>=6)
            if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>max(a[i],a[i+1])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>max(a[i+2],a[i+3])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>max(a[i+4],a[i+5]))
                ans++;
        if(n>=7)
            if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]>max(a[i],a[i+1])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]>max(a[i+2],a[i+3])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]>max(a[i+5],a[i+4])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]>max(a[i+5],a[i+6]))
                ans++;
        if(n>=8)
            if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]>max(a[i],a[i+1])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]>max(a[i+2],a[i+3])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]>max(a[i+5],a[i+4])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]>max(a[i+6],a[i+7]))
                ans++;
        if(n>=9)
            if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]>max(a[i],a[i+1])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]>max(a[i+2],a[i+3])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]>max(a[i+5],a[i+4])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]>max(a[i+6],a[i+7])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]>max(a[i+7],a[i+8]))
                ans++;
        if(n>=10)
            if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]+a[i+9]>max(a[i],a[i+1])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]+a[i+9]>max(a[i+2],a[i+3])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]+a[i+9]>max(a[i+5],a[i+4])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]+a[i+9]>max(a[i+6],a[i+7])&&a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]+a[i+9]>max(a[i+8],a[i+9]))
               ans++;
    }
    cout<<ans<<endl;
    return 0;
}
