#include<bits/stdc++.h>
using namespace std;
int a[120];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n,s=1,ans1,ans2;
cin>>n>>m>>a[1];
for(int i=2;i<=n*m;i++)
{
    cin>>a[i];
    if(a[i]>a[1]) s++;
}
if(s%n==0) ans1=s/n;
else ans1=s/n+1;
if(ans1%2!=0)
{
    if(s%n==0) ans2=n;
    else ans2=s%n;
}
else if (ans1%2==0)
{
    if(s%n==0) ans2=1;
    else ans2=n-s%n+1;
}
cout<<ans1<<" "<<ans2;
return 0;
}
