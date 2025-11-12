#include <bits/stdc++.h>
using namespace std;
int n,k,a[50005],ans;
bool pd1=1,pd2=1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
        if(a[i]!=1)
            pd1=0;
        if(a[i]>1)
            pd2=0;
    }
    if((pd1)&&(k==0))
    {
        cout <<n/2;
        return 0;
    }
    else if((pd1)&&(k==1))
    {
        cout <<n;
        return 0;
    }
    else if((pd2)&&(k==0))
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
                ans++;
            else if(a[i+1]==1)
            {
                ans++;
                i++;
            }
        }
        cout <<ans;
        return 0;
    }
    else if((pd2)&&(k==1))
    {
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                ans++;
        cout <<ans;
        return 0;
    }
    else
    {
        int b[50005];
        for(int i=1;i<=n;i++)
        {
            int y=a[i];
            if(i==k)
            {
                b[i]=i;
                continue;
            }
            for(int j=i+1;j<=n;j++)
            {
                if(y^a[j]==k)
                {
                    b[i]=j;
                    break;
                }
                y^=a[j];
            }
        }
        for(int i=1;i<=n;)
            for(int j=i;j<=n;j++)
                if(b[j]<b[j+1])
                {
                    i=j;
                    ans++;
                    break;
                }
        cout <<ans;
    }
    return 0;
}
