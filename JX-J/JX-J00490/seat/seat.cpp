#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
  int n,m;
  cin>>n>>m;
  int wt=0;
  int ans[n*m+10]={0};
  for(int i=1;i<=n*m;i++)
  {
      cin>>ans[i];
      if(i==1)
        wt=ans[i];
  }
  int wtr=0;
  sort(ans+1,ans+1+n*m);
  for(int i=1;i<=n*m;i++)
  {
      if(ans[i]==wt){
        wtr=n*m-i+1;
        break;
      }
  }
  int k=wtr/n;
  if(k*n==wtr)
  {
      if(k%2==0)
        cout<<k<<' '<<1;
      else
        cout<<k<<' '<<m;
  }
  else
  {
      if(k%2==0)
        cout<<k+1<<' '<<wtr-k*n;
    else
        cout<<k+1<<' '<<m-wtr+k*n+1;
  }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
