#include<bits/stdc++.h>
using namespace std;
long long n,k,ans = 0,temp=0;
long long a[1000005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        temp = temp^a[i];
        if(a[i] == k || temp == k)
        {
            ans++;
            temp = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
