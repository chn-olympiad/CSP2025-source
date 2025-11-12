#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a,c,da=1,f;
int b[1000];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>a>>c;
for(int i=0;i<a*c;i++){cin>>b[i];f=b[0];if(f<b[i]){da+=1;}}
if(da%c==0){cout<<da/c<<" "<<c;}
else cout<<da/c+1<<" "<<da%c;
return 0;
}





