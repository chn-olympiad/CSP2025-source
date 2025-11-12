#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int k,c[1000000]={0},n=0,f;
string s;
cin>>s;
s=s+"00";
int i=0;
for( i=0;i<=1000000;i++ ){
     if(int(s[i])==48||int(s[i+1])==48){
       k=i;
       break;
}
}

  for( i=0;i<=k;i+=1 ){
    if(int(s[i])>48&&int(s[i])<57){
       c[n]=int(s[i])-48;
       n++;
    }
    if(int(s[i])==48){
       c[n]=0;
       n++;
    }
    if(int(s[i])==57){
       c[n]=9;
       n++;
    }
  }

sort(c+0,c+n+1 );
for( int p=n;p>=1;p-- ){
    cout<<c[p];
}
return 0;
}
//48 57
