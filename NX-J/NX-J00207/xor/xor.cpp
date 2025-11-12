#include <bits/stdc++.h>
using namespace std;
long long a[100005],n,k,cnt,s[1000005];
bool vis[1000005]={false};
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]^s[i-1]==k)
        {
            cnt++;
        }
    }
    cout<<cnt+1;






    return 0;
}
