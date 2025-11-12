#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int t,n;
  cin>>t;
  while (t--)
  {
    int ans=0;
    cin>>n;
    vector<tuple<int,int,int>> a(n);
    for (auto &[x,y,z]:a)
      cin>>x>>y>>z;
    if ([&]()
    {
      for (auto &[x,y,z]:a)
        if (z) return false;
      return true;
    }())
    {
      int cnt=0;
      vector<tuple<int,int,int>> b(n);
      for (int i=0;i<n;i++)
      {
        auto [x,y,z]=a[i];
        auto &[diff,u,v]=b[i];
        u=x,v=y;
        diff=abs(u-v);
      }
      sort(b.begin(),b.end(),greater<tuple<int,int,int>>());
      for (auto [_,x,y]:b)
      {
        if (x>y)
        {
          if (cnt*2<n) 
          {
            ans+=x;
            cnt++;
          }
          else ans+=y;
        }
        else
        {
          if ((n-cnt)*2<n) ans+=y;
          else 
          {
            ans+=x;
            cnt++;
          }
        }
      }
      cout<<ans<<'\n';
    }
    else
    {
      int maxn=0,cnt1=0,cnt2=0,cnt3=0;
      auto dfs=[&](auto &self,int now)
      {
        if (cnt1*2>n||cnt2*2>n||cnt3*2>n) return;
        if (now==n) maxn=max(maxn,ans);
        auto [x,y,z]=a[now];
        for (int i=0;i<3;i++)
        {
          if (i==1)
          {
            ans+=x;
            cnt1++;
            self(self,now+1);
            ans-=x;
            cnt1--;
          }
          else if (i==2)
          {
            ans+=y;
            cnt2++;
            self(self,now+1);
            ans-=y;
            cnt2--;
          }
          else 
          {
            ans+=z;
            cnt3++;
            self(self,now+1);
            ans-=z;
            cnt3--;
          }
        }
      };
      dfs(dfs,0);
      cout<<maxn<<'\n';
    }
  }
}
