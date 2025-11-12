#include<bits/stdc++.h>
using namespace std;
int n,m,s,ans,j,x,y,a[100];
int main()
{
freopen("seat.in","r","stdseat.in");
     freopen("seat.out","w","stdseat.out");
   cin>>n>>m;
    s=n*m;
    for(int i=1; i<=s; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=s; i++)
    {
        ans=a[i];
        if(a[0]>a[i])
             ans=++;
    }
j=ans\n;
y=j;
if(j%2==0){
    x=ans%n;
cout<<x<<" "<<y;
} x=n-ans%n;
  cout<<x<<" "<<y;
    return 0;
}
