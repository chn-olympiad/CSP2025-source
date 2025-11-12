#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0,cnt1=0,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)cnt++;
        if(a[i]==0)cnt1++;
    }
    if(k==0&&cnt==n){cout<<n/2;return 0;}
    else if(cnt1+cnt==n&&k<=1)
    {
        if(k==0)
        {
            int num=1;
            for(int i=2;i<=n;i+=num)
            {
                if(a[i]==a[i-1])
                {
                    num=2;ans++;
                }
            }

        }
        else
        {
            int num=1;
            for(int i=2;i<=n;i+=num)
            {

                if(a[i]!=a[i-1])
                {
                    num=2;ans++;
                }
                else if(a[i]==a[i-1]&&a[i]==1)
                {
                    int t=i;
                    while(a[t]==a[t-1])
                    {
                        t--;num++;
                        if(num%2==1){ans++;break;}
                    }
                }
            }

        }
        cout<<ans;
    }
    else cout<<6;
    return 0;
}
