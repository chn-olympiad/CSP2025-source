#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int cnt=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==1)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)cnt++;
        }
        cout<<cnt;
    }
    else if(k==0)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)cnt++;
        }
        cnt=cnt+(n-cnt)/2;
        cout<<cnt;
    }
    else
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==k)cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
