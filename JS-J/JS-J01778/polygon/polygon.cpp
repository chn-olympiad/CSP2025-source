#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

int n;
const int N=5005;
int a[N];

signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(n==4)
    {
        if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))
        {
            ans++;
        }
        if(a[1]+a[2]+a[4]>2*max(max(a[1],a[2]),a[4]))
        {
            ans++;
        }
        if(a[1]+a[4]+a[3]>2*max(max(a[1],a[4]),a[3]))
        {
            ans++;
        }
        if(a[4]+a[2]+a[3]>2*max(max(a[4],a[2]),a[3]))
        {
            ans++;
        }
        if(a[1]+a[2]+a[3]+a[4] > 2*max(max(a[1],a[2]) , max(a[4],a[3])))
        {
            ans++;
        }
        cout<<ans;
    }
    else if(n==5)
    {
        if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))
        {
            ans++;
        }
        if(a[1]+a[2]+a[4]>2*max(max(a[1],a[2]),a[4]))
        {
            ans++;
        }
        if(a[1]+a[2]+a[5]>2*max(max(a[1],a[2]),a[5]))
        {
            ans++;
        }
        if(a[1]+a[4]+a[3]>2*max(max(a[4],a[1]),a[3]))
        {
            ans++;
        }//
        if(a[1]+a[5]+a[3]>2*max(max(a[1],a[5]),a[3]))
        {
            ans++;
        }
        if(a[1]+a[5]+a[4]>2*max(max(a[1],a[5]),a[4]))
        {
            ans++;
        }
        if(a[2]+a[4]+a[3]>2*max(max(a[2],a[4]),a[3]))
        {
            ans++;
        }
        if(a[2]+a[4]+a[5]>2*max(max(a[2],a[4]),a[5]))
        {
            ans++;
        }
        if(a[5]+a[2]+a[3]>2*max(max(a[5],a[2]),a[3]))
        {
            ans++;
        }//
        if(a[4]+a[5]+a[3]>2*max(max(a[5],a[4]),a[3]))
        {
            ans++;
        }
        if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[4],a[3])))
        {
            ans++;
        }
        if(a[1]+a[2]+a[3]+a[5]>2*max(max(a[1],a[2]),max(a[5],a[3])))
        {
            ans++;
        }
        if(a[1]+a[2]+a[5]+a[4]>2*max(max(a[1],a[2]),max(a[4],a[5])))
        {
            ans++;
        }//
        if(a[1]+a[5]+a[3]+a[4]>2*max(max(a[1],a[5]),max(a[4],a[3])))
        {
            ans++;
        }
        if(a[4]+a[2]+a[3]+a[5]>2*max(max(a[4],a[2]),max(a[5],a[3])))
        {
            ans++;
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]>=2*max(max(max(a[4],a[2]),max(a[5],a[3])),a[1]))
        {
            ans++;
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
