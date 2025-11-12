#include<bits/stdc++.h>

using namespace std;

const int MAXN=5e5+7;
long long a[MAXN];
long long t[MAXN]={0};
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,cnt=0,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum=a[i];
            for(int k=i+1;k<=j;k++)
            {
                sum=(sum^a[k]);

            }

            if(sum==k&&t[i]==0&&t[j]==0)
            {
                cnt++;
                if(i==j)
                    t[i]++;
                else
                {
                    for(int q=i;q<=j;q++)
                    {
                       t[q]++;
                    }

                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
