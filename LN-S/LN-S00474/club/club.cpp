#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010],c[10010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,sum=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt0=0,cnt1=0,cnt2=0;
        int g[100];
        if(n==2)
        {
            int a1,a2,a3,a4,a5,a6;
            cin>>a1>>a2>>a3>>a4>>a5>>a6;
            int n=0;
            n=max(n,a1+a5);
            n=max(n,a1+a6);
            n=max(n,a2+a4);
            n=max(n,a2+a6);
            n=max(n,a3+a4);
            n=max(n,a3+a5);
            cout<<n<<"\n";
        }
        else
        {
            for(int k=1;k<=n;k++)
            {
                cin>>a[k]>>b[k]>>c[k];
            }
            for(int i=0;i<pow(3,n);i++)
            {
                int p=0;
                while(i!=0)
                {
                    g[++p]=i%3;
                    if(i%3==0)
                    {
                        cnt0++;
                    }
                    else if(i%3==1)
                    {
                        cnt1++;
                    }
                    else
                    {
                        cnt2++;
                    }
                    i/=3;
                }
                if(cnt0>n/2||cnt1>n/2||cnt2>n/2)
                {
                    continue;
                }
                int sum=0,ans=0;
                for(int j=1;j<=n;j++)
                {
                    if(g[j]==0)
                    {
                        sum+=a[j];
                    }
                    else if(g[j]==1)
                    {
                        sum+=b[j];
                    }
                    else
                    {
                        sum+=c[j];
                    }
                }
                ans=max(ans,sum);
            }
            cout<<sum<<"\n";
        }
    }
    return 0;
}
