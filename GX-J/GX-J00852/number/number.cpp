#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("number.in","r",stdin);
     freopen("number.out","r",stdin);
     string s;
     int a[1000],b[1000];
     cin>>s;
     for(int i=0;i<s;i++){
         a[i]==0;
         b[i]==0;
     }
     for(int i=0;i<s;i++){
         if(s[i]/s[i]==1){
            a[i]==s[i];
         }
     }
     for(int i=0;i<s;i++){
         if(a[i+1]>a[i]){
             b[i]==a[i+1];
             a[i+1]==a[i];
             a[i]==b[i];
         }
     }
     for(int i=0;i<s;i++){
         cout<<a[i];
     }
    return 0;
}
