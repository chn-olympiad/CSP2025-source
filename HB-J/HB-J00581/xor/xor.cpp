#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,k;
int a[N],f[N],flag[N],ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)f[i]=f[i-1]^a[i];
    int now=0;
    for(int i=1;i<=n;i++)
    {
        flag[k^f[i-1]]=i;
        if(flag[f[i]]>now||k==a[i])
        {
            ans++;
            now=i;
            flag[f[i]]=-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}