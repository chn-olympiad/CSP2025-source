#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans,temp,p,q;
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
        for(int j=i;j<=n;j++)
        {
            if(i==j&&a[i]==k)
            {
                p=i;
                q=j;
                ans++;
            }
            else
            {
                for(int m=i;m<=j;m++)
                {
                    temp=a[m]^temp;
                    if(temp==k&&(i==p||j==p||i==q||j==q)&&i!=j&&q!=p)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
