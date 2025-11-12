#include<bits/stdc++.h>
#define E 1000010
using namespace std;
int n,k,a[E],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==0)
    {
        for(int i=1;i<=n;i++)
            if(a[i]==k)
                ans++;
    }
    cout<<ans;
    return 0;
}
