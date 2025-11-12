#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,a,b,c,max=-1;
cin>>n>>a>>b>>c;
if(a>max) max=a;
if(b>max) max=b;
if(c>max) max=c;
if(a+b+c>2*max) cout<<1;
else cout<<0;
return 0;
}
