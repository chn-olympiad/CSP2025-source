#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n,i,ai1,ai2,ai3;
cin>>t;
cin>>n;
for(i>=1;i<=n;i++)
{
    cin>>ai1>>ai2>>ai3;
    cout<<ai1/3<<" "<<ai2/3<<" "<<ai3/3;
}
return 0;
}
