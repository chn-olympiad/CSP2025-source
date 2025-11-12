#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int x;
    cin>>x;
    for(int i=1;i<=x;i++)
    {
        int n,ans=0,k0[n]={0},k1[n]={0},k2[n]={0};
        cin>>n;
        int a[n][3];
        for(int j=0;j<n;j++)
            cin>>a[j][0]>>a[j][1]>>a[j][2];
        for(int j=0;i<n;j++)
        {
            if(max(a[j][0],max(a[j][1],a[j][2]))==a[j][0])
                k0[j]=a[j][0];
            if(max(a[j][0],max(a[j][1],a[j][2]))==a[j][1])
                k1[j]=a[j][1];
            if(max(a[j][0],max(a[j][1],a[j][2]))==a[j][2])
                k2[j]=a[j][2];
        }
        int cnt0=0,cnt1=0,cnt2=0;
        for(int j=0;j<n;j++)
        {
            if(k0[j]!=0)
                cnt0++;
            else if(k1[j]!=0)
                cnt1++;
            else if(k2[j]!=0)
                cnt2++;
        }
        if(cnt0<=n/2 && cnt1<=n/2 && cnt2<=n/2)
        {
            for(int j=0;j<n;i++)
                ans+=max(a[j][0],max(a[j][1],a[j][2]));
            cout<<ans<<endl;
        }
    }
    return 0;
}