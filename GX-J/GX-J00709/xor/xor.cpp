
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,a[10001],ans;
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
  {
    if(a[i]==k)
    {
      ans++;
    }
    //else
      //for(int j=i+1;j<=n;j++)
      //{
        //for(int k=i;k<=j;k++)
            //if(v[a[k])
              //j=k-1;

      //}
  }
  cout<<ans;
  return 0;
}

