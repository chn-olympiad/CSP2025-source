#include<bits/stdc++.h>
using namespace std;
int n,ans=0,k;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
            ans++;
    }
    for(int i=1;i<=n;i+=2)
    {
        if(a[i]==a[i+1])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
