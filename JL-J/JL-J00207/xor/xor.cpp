#include<bits/stdc++.h>
using namespace std;
int s[10000890];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int si,k,ans=0;
    cin>>si>>k;
    for(int i=1;i<=si;i++)
            cin>>s[i];
    if(k==0)
    {
        for(int i=1;i<=si;i++)
        {
            if(s[i]==0)
                    ans++;
            else if(s[i]==1&&s[i+1]==1)
            {
                ans++;
                i++;
            }
        }
    }
    if(k==1)
    {
        for(int i=1;i<=si;i++)
        {
            if(s[i]==1)
                ans++;
            else if(s[i]==0&&s[i+1]==1)
            {
                ans++;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
