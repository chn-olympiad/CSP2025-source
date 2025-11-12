#include <iostream>
#include <algorithm>
using namespace std;
int f[505][505][105],a[505],n,ans;
const int M=998244353;
int dfs(int b,int sum,int num,int m)
{
    if(num==m+1)
    {
        if(sum>b)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return dfs(b,sum+a[num],num+1,m)+dfs(b,sum,num+1,m);

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    f[0][0][0]=1;
    //for(int i=1;i<n;i++)
    //{
       // f[i][0][0]=1;
        //for(int j = 1;j<=i;j++)
        //{
        //    for(int k = 0;k<=8;k++)
        //    {
       //         x=0;
       //         if(k-a[i]>0)
        //            x=k-a[i];
        //        f[i][j][k]=f[i-1][j-1][x]+f[i-1][j][k];
         //       cout << i<< " "<<j<< " "<< k<<" "<<f[i][j][k]<<endl;
         //   }
        //}
    //}
    int x=1;
    if(n<=20)
    {
        for(int i = 3;i<=n;i++)
        {
            ans=(ans+dfs(a[i],0,1,i-1))%M;

        }
    }
    else
    {
        for(int i = 3;i<=n;i++)
        {
            x=1;
            for(int j = n;j>=n-i+1;j--)
            {
                x=(x*j)%M;
            }
            for(int j = 1;j<=n;j++)
                x/=j;
            ans=(ans+x)%M;
        }
    }
    cout <<ans;
    return 0;
}
