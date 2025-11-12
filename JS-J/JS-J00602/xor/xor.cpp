#include<bits/stdc++.h>
using namespace std;
int n,k,a[600000],an;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1)
        {
            break;
        }
        if(i==n&&k==0)
        {
            cout<<n/2;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1&&a[i]!=0)
        {
            break;
        }
        if(i==n)
        {
            if(k==1)
            {
                for(int j=1;j<=n;j++)
                {
                    if(a[j]==1)
                    {
                        an++;
                    }
                }
                cout<<an;
            }
            if(k==0)
            {
                for(int j=1;j<=n;j++)
                {
                    if(a[j]==0)
                    {
                        an++;
                    }
                    if(a[j]==1&&a[j+1]==1)
                    {
                        an++;
                        j+=1;
                    }
                }
                cout<<an;
            }
        }
    }
    return 0;
}
