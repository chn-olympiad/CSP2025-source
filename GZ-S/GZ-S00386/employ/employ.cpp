//GZ-S00386 毕节东辰实验学校 苏长灵珠
#include<bits/stdc++.h>
using namespace std;
const int N=500+50;
long long  n,m,k,t,ans;
struct node{
    int m,w;
    int k2;
};
long long s[N];
long long maxx=998244353;
long long a[N];
int main()
{
    int num=0;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
       cin>>s[i];
       num++;
   }
  for(int i=1;i<=n;i++)
  {

      cin>>a[i];
  }

  for(int i=1;i<=n;i++)
  {
      int k=n*(n-1);
      n-=1;
  }
  for(int i=1;i<=m;i+=)
  {
      int p=m*(m-1);
      m-=1;
  }
  int ans=k/p;
  if(num==1)
  {
      if(s[1]==0)cout<<0;
    else cout<<ans;return 0;
  }
  else cout<<ans%maxx;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
