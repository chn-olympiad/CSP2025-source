#include <bits/stdc++.h>
using namespace std;

int a[500005];
int fl0,fl1,fl2;
long long ans=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)fl1=1;
        else if(a[i]==0)fl0=1;
        else fl2=1;
    }
    if(fl1&&(!fl0)&&(!fl2))//xingzhiA
    {
        if(k==0)
        {
            cout<<n/2;
        }
        else cout<<n/k;
        return 0;
    }
    else if(fl1&&fl0&&(!fl2))//xingzhiB
    {
        if(k==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)ans++;
                else
                {
                    if(a[i]==a[i-1]&&a[i-1]==1)
                    {
                        ans++;
                        a[i]=0;
                        a[i-1]=0;
                    }
                }
            }
            cout<<ans;
            return 0;
        }
        if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    cout<<n/k;


    return 0;
}
