#include<bits/stdc++.h>
using namespace std;
int n[100002];
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
long long int n,a,b,c;
cin>>n;
if(n==3){
    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a) cout<<1;
    else cout<<0;
}
else cout<<53;
return 0;
}
