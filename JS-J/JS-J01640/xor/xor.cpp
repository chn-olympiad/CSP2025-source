#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,k;
int a[MAXN];
int ans=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            ans++;
        }
        else if(a[i]^a[i+1]==k)
        {
            i++;
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
