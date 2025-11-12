#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned int a[11];
signed main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   while(1){
       char c;
       c=getchar();
       if(c=='\n'){
           break;
       }
       if(c<'a'){
           int n=c-48;
           a[n]++;
       }
   }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
