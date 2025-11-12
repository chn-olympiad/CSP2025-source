#include <bits/stdc++.h>
using namespace std;
int n,a[5005],maxxx,cnt,ans;
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  if(n<3) cout<<0<<endl;
  if(n==3)
  {
  	for(int i=1;i<=n;i++)
    {
  	  maxxx=max(maxxx,a[i]);
      cnt+=a[i];
    }
    if(cnt>maxxx*2) cout<<1<<endl;
    cout<<0<<endl;
  }
  if(n>3)
  {
  	for(int i=1;i<=n;i++)
    {
  	  maxxx=max(maxxx,a[i]);
      cnt+=a[i];
      if(cnt>maxxx*2) 
      {
      	ans++;
      	maxxx=0;
      	cnt=0;
      	continue;
	  }
    }
    cout<<ans%998244353<<endl;
  }
  return 0;
}
