#include<bits/stdc++.h>
using namespace std;
int n,k,p,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int f;
        cin>>f;
        p=p^f;
        if(k==p)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
