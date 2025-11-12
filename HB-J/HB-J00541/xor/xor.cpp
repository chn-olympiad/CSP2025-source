#include<bits/stdc++.h>
using namespace std;

long long n,k,r,a[100005],q,ans=0;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>q;
        a[i]=a[i-1]^q;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[j]^a[i]==k)
            {
                i=j+1;
                ans++;
                break;
            }
        }
    }
    cout<<ans;
}
