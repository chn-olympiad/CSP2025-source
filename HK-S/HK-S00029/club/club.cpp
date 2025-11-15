#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int t=0;
  cin>>t;
  for (int i =1;i<=t;i++)
  {
    long long n=0,max_satisfaction=0;
    cin >> n;
    long long a[100005][5];
    for (int j=1;j<=n;j++)
    {
      long long max[2],ans=0;
      max[0]=-1;
      for(int k=1;k<=3;k++)
      {
        cin >> ans;
        if (ans>max[0])
        {
          max[0]=ans;
          max[1]=k;
        }
      }
      max_satisfaction+=max[0];
    }
    cout << max_satisfaction<<endl;
  }
  return 0;
}
