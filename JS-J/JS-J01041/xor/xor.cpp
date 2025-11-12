#include<bits/stdc++.h>
using namespace std;
int n,k;
int a_[1005];
bool a[21][1005];
int sum[21][1005];
int fk[25];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<=20;i++)
    {
        fk[i]=k&1;
        k>>=1;
//        cout<<fk[i]<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a_[i];
    }
    for(int i=1;i<=n;i++)
    {
        int num=a_[i];
        int w=0;
        while(num)
        {
            a[w][i]=num&1;
            w++;
            num>>=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=20;j++)
        {
            sum[j][i]=sum[j][i-1]+a[j][i];
        }
    }
//    for(int i=0;i<=20;i++)
 //   {
 //       for(int j=1;j<=n;j++)
 //       {
 //           cout<<sum[i][j]<<" ";
  //      }
 //       cout<<endl;
 //   }
    int ans=0;
    int l=1;
    for(int j=1;j<=n;j++)
    {
        for(int pre=j;pre>=l;pre--)
        {
            int num[25]={0};
            for(int i=0;i<=20;i++)
            {
                num[i]=(sum[i][j]-sum[i][pre-1])%2;
            }
            bool flag=true;
            for(int i=0;i<=20;i++)
            {
                if(num[i]!=fk[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                ans++;
                l=j+1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
