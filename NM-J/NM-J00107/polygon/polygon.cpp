#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,s,h=0,m=0,w=0;
cin>>s;
for(int i=0;i<s;i++){
    cin>>n;
    if(n>h)
        h=n;
    m+=n;
}
   if(m>h*2)
    cout<<1;
   else
    cout<<0;

return 0;
}
