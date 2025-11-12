#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,k,ans;
int a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=0,flag=1;
    while(flag<=n)
    {
        cnt^=a[flag];
        if(cnt==k) ans++,cnt=0;
        flag++;
    }
    cout<<ans;
    return 0;
}
