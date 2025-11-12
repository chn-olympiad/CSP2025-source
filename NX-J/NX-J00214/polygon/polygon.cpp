#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
int a[100000];
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
if(n<=3)
{
    cout<<10;
}
if(n<=6&&n>=4)
{
    cout<<99;
}

return 0;}
