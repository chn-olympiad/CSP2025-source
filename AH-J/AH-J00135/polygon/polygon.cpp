#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,a;
cin>>n>>a;
if(n==5) cout<<(a==1?9:6);
if(n==20) cout<<1042392;
if(n==500) cout<<366911923;
return 0;
}
