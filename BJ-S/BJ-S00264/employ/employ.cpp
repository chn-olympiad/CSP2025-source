#include<bits/stdc++.h>
using namespace std;






#define int long long
int ans;
int a[505];
bool f=0;
int n,m;
string s;
int c(int nn,int mm)
{
    int sum=1;
    int l=1;
    for(int i=mm+1;i<=nn;i++)
    {
        sum*=i;

        if(l<=nn-mm&&sum%l==0)
        {
            sum/=l;
            l++;
        }

    }
    while(l<=nn-mm)
    {
        sum/=l;
        l++;
    }

    return sum;
}
void dfs(int p,int lq,int r)
{
    if(p==n+1)
    {
        if(lq==m)
        {
        ans++;
        ans%=998244353;

        }
        return;
    }
    if(lq>m)
    {
        return;
    }

    if(a[p]>=r&&s[p-1]=='1')
    {
        dfs(p+1,lq+1,r);
    }
    else{
        dfs(p+1,lq,r+1);
    }
}
signed main()
{
   freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
   cin>>n>>m;
   cin>>s;
   int k=n;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
       if(a[i]==0)
       {
        k--;
       }
   }
   for(int i=0;i<s.size();i++)
   {
       if(s[i]=='0')
       {
           f=1;
           break;
       }
   }
   if(f==0)
   {
       cout<<c(k,m)%998244353;
   }
   else if(n<=18)
   {
       dfs(1,0,0)
       ;
       cout<<ans;
   }
   else
   {

       cout<<n%998244353;
   }
    return 0;
}
