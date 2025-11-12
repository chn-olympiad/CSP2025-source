#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned long long rp=-1;
const int mod=998244353;
int n,a[5005],s[5005];
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
    if(n==3)
    {
        if(2*max({a[1],a[2],a[3]})<a[1]+a[2]+a[3])
            cout<<1;
        else cout<<0;
    }
    return 0;
}

//mo bai xst dalao!
//mo bai wyx dalao!
//mo bai cyh dalao!
//#Shang4Shan3Ruo6Shui4
