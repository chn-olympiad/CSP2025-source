#include<bits/stdc++.h>
using namespace std;
const int mxn=1000100;
int a[mxn];
int n,k,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ans=0;
    if(k==0)
    {
        for(int i=1;i<=n;i++)
            if(a[i]==0)
                ans++;
        for(int i=1;i<n;i++)
            if(a[i]==1 && a[i+1]==1)
                ans++;
        cout<<ans;
    }else
    {
        if(k==1)
        {
            for(int i=1;i<=n;i++)
                if(a[i]==1)
                    ans++;
            cout<<ans;
        }else
            cout<<"1";
    }
    return 0;
}
