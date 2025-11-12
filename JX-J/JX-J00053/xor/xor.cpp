#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 5*10e5+100;
int a[MAX_N];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k,ans=0;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i]^=a[i-1];

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int s=a[j]^a[i-1];
            if(s==k)
            {
                ans++;
                i=j+1;
                j=i;
            }
        }
    }

    cout<<ans;
    return 0;
}
