#include<bits/stdc++.h>
using namespace std;
int b[12]={};
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
for(int i=0;i<a.size();i++){
  if(int(a[i])>=48 and int(a[i])<=57){
    b[int(a[i])-48]++;
  }
}
for(int i=9;i>=0;i--){
    if(b[i]>0){
        for(int j=1;j<=b[i];j++){
            cout<<i;
        }
    }
}
return 0;
}

