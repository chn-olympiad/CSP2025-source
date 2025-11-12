#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct St
{
  ll a;
  ll b;
  ll c;
  ll cha;
  ll _Max;
};
inline ll ch(ll a,ll b,ll c)
{
  ll d[3];
  d[0]=a;
  d[1]=b;
  d[2]=c;
  sort(d,d+3);
  return d[2]-d[1];
}
inline ll Ma(ll a,ll b,ll c)
{
  ll d1=max(a,b);
  ll d=max(d1,c);
  if(a==d) return 1;
  if(b==d) return 2;
  if(c==d) return 3;
  return 0;
}
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ll t,ii;
  cin>>t;
  for(ii=t;ii!=0;ii--)
  {
    ll n,i;
    ll ans=0;
    cin>>n;
    struct St x[n+1];
    for(i=1;i<=n;i++)
    {
      cin>>x[i].a>>x[i].b>>x[i].c;
      x[i].cha=ch(x[i].a,x[i].b,x[i].c);
      x[i]._Max=Ma(x[i].a,x[i].b,x[i].c);
    }
      ll A[n+1],B[n+1],C[n+1],na=0,nb=0,nc=0;
    for(i=1;i<=n;i++)
    {
      if(x[i]._Max==1)
      {
        na++;
        A[na]=i;
        continue;
      }
      if(x[i]._Max==2)
      {
        nb++;
        B[nb]=i;
        continue;
      }
      if(x[i]._Max==3)
      {
        nc++;
        C[nc]=i;
        continue;
      }
    }
    for(i=1;i<=na;i++)
    {
      ans=ans+x[A[i]].a;
    }
    for(i=1;i<=nb;i++)
    {
      ans=ans+x[B[i]].b;
    }
    for(i=1;i<=nc;i++)
    {
      ans=ans+x[C[i]].c;
    }
    ll l=n/2;
    if(na>l)
    {
      ll r=na-l;
      ll R[na+1];
      for(i=1;i<=na;i++)
        R[i]=x[A[i]].cha;
      sort(R+1,R+na+1);
      for(i=1;i<=r;i++)
        ans=ans-R[i];
    }
    else if(nb>l)
    {
      ll r=nb-l;
      ll R[nb+1];
      for(i=1;i<=nb;i++)
        R[i]=x[B[i]].cha;
      sort(R+1,R+nb+1);
      for(i=1;i<=r;i++)
        ans=ans-R[i];
    }
    else if(nc>l)
    {
      ll r=nc-l;
      ll R[nc+1];
      for(i=1;i<nc;i++)
        R[i]=x[C[i]].cha;
      sort(R+1,R+nc+1);
      for(i=1;i<=r;i++)
        ans=ans-R[i];
    }
    cout<<ans<<endl;
  }
  return 0;
  }
