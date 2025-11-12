#include<bits/stdc++.h>
using namespace std;
int n,a[500010],dp[1010][1010],k,end1=0,ans=0;
int pre(int a,int b)
{int m=0;
 int max1=max(a,b);
 int t=a%2;
 int p=b%2;
 int cnt=0;
 if(t!=p)cnt++;
 a=a>>1;
 b=b>>1;
 while(max1!=0)
  {m++;
   int q=a%2;
   int l=b%2;

   if(q!=l)cnt+=pow(2,m);
   //cout<<cnt<<' ';
   a=a>>1;
   b=b>>1;
   max1=max1>>1;
  }
 return cnt;
}
int main()
{ freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
 cin>>n>>k;
 for(int i=1;i<=n;i++)
   cin>>a[i];
 //for(int i=1;i<=n;i++)
   // for(int j=i+1;j<=n;j++)

  dp[1][1]=a[1];
 for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
       dp[i][j]=pre(dp[i][j-1],a[j]);
 for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
        if(dp[i][j]==k&&i>end1)
         {ans++;
          end1=j;
          i=end1;
          //cout<<pre(1,3)<<' ';
          }
 cout<<ans;

 //cout<<pre(8,6);
  return 0;
 }

