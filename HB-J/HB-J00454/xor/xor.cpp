#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+5];
    int x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            x++;
        }
        else
        {
            y++;
        }
    }
    if(x==n)
    {
        cout<<n/2;
        return 0;
    }
    else
    {
        if(k==0)
        {
            int s=y;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1&&a[i+1]==1)
                {
                    s+=1;
                    i++;
                }
            }
            cout<<s;
        }
        else
        {
            int s=x;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0&&a[i+1]==0)
                {
                    s+=1;
                    i++;
                }
            }
            cout<<s;
        }
    }
    return 0;
}
