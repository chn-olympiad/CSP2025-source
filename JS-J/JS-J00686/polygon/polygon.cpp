#include<iostream>
using namespace std;
int main()
{
    //freopen("polygon.in","r","stdin");
    //freopen("polygon.out","r","stdout");
    int a[i],n,i,j,k,s;
    cin>>n;
    s=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
       for(j=i+1;i<=n;j++)
          for(k=j+1;k<=n;k++)
          {
             if(i+k+j>max(i,j,k)*2)
               s++;
          }
    cout<<s%998244353
    return 0;
}
