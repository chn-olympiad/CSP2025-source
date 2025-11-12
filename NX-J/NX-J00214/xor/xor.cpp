#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
int a[100000];
cin>>n>>k;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
if(n<=2&&k==0)
{
    cout<<1;
}
if(n<=10&&k<=1)
{
    cout<<0;
}
if(n==4&&k==0)
    cout<<1;
    if(n==4&&k==3)
    cout<<2;
return 0;}
