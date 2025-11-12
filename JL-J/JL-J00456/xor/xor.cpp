#include<bits/stdc++.h>
using namespace std;
int n,k,ans,x;
int main()
{
    freopen("xor.in","r",stdin);
    cin>>n>>k;
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x==0) ans++;
        }
    }
    else if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x==1) ans++;
        }
    }
    freopen("xor.out","w",stdout);
    cout<<ans;
    return 0;
}
