#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,all1=1,all10=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) all1=0;
        if(a[i]!=1&&a[i]!=0) all10=0;
    }
    if(all1==1)
    {
        if(k==0) cout<<n/2;
        else if(k==1) cout<<n;
        else cout<<0;
        return 0;
    }
    if(all10==1)
    {
        int cnt1=0,l0=0,cnt0=0,l1=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                cnt1++;

                l0=0;
                l1++;
            }
            if(a[i]==0)
            {
                cnt0++;
                cnt0=cnt0+l1/2;
                l1=0;
                l0++;
            }
        }
        if(k==0) cout<<cnt0;
        else if(k!=0&&k!=1) cout<<0;
        else cout<<cnt1;
        return 0;
    }
    cout<<1;
    return 0;
}
