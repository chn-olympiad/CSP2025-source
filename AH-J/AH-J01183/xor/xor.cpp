#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt,ans,flag=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)cnt++;
        else ans++;
        if(a[i]==0)flag=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1]&&a[i]==1)
        {
            a[i+1]=0;
            ans++;
        }
    }
    if(k==1)cout<<cnt;
    if(k==0&&flag==0)cout<<cnt/2;
    if(k==0&&flag==1)cout<<ans++;

    return 0;
}
//10 1 0 11
