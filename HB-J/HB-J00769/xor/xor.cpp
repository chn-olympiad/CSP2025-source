#include <bits/stdc++.h>
using namespace std;
int a[500005]={0},s[500005][3]={0}/*0 st 1 ed*/,shd=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    bool flag=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            flag=0;
        }
    }
    if(k==0&&flag==1)
    {
        cout<<n/2;
    }
    else
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int ans=a[i];
                for(int l=i+1;l<=j;l++)
                {
                    ans=ans^a[l];
                }
                if(ans==k)
                {
                    shd++;
                    s[shd][0]=i;
                    s[shd][1]=j;
                    break;
                }
            }
        }
        for(int i=1;i<=shd;i++)
        {
            if(i==1){s[i][2]=1;}
            else
            {
                int countt=0,wei=0;
                for(int j=1;j<=shd;j++)
                {
                    if(s[j][2]==1&&s[j][1]>=s[i][0])
                    {
                        countt++;
                        wei=j;
                    }
                }
                if(countt==0)
                {
                    s[i][2]=1;
                }
                else if(countt==1)
                {
                    if(s[i][1]<=s[wei][1])
                    {
                        s[wei][2]=0;
                        s[i][2]=1;
                    }
                }
            }
        }
        for(int i=1;i<=shd;i++)
        {
            if(s[i][2]==1)
            {
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}//Score++65 Score--30
