#include<iostream>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long n;
    cin>>n;
    int m=3;
    cin>>m;
   for(int i=1;i<=n/2;i++)
   {
       int ai1,ai2,ai3;
       cin>>ai1>>ai2>>ai3;
      if(ai1>ai2>ai3)
      {
           i=ai1;

      }
      else if(ai2>ai1>ai3)
      {
          i=ai2;

      }
      else if (ai3>ai2>ai1){
        i=ai3;

      }
      int sum;
      cin>>sum;
i+=sum;

       cout<<sum;
   }


    return 0;
}
