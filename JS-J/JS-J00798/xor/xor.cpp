#include<bits/stdc++.h>
using namespace std;
/*int yh(int a,int b)
{
    if(a==b) return 0;
    else return 1;
}*/
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
      //  sum+=a;
    }
  //  if(sum==n)
    for(int i=2;i<=n;i=i+2){
       sum+=n-i+1;
    }
    cout<<sum;
    return 0;
}
