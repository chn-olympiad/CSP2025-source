#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[5005]={};
    for(int i=0;i<n;i++)
       {
          cin>>a[i];
       }
    int cnt=1;
    if(a[0]>=a[1]+a[2])
    cnt=0;
    if(a[1]>=a[0]+a[2])
    cnt=0;
    if(a[2]>=a[1]+a[0])
    cnt=0;
    cout<<cnt;
    return 0;
}
