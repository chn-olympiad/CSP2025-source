#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int j=0;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
   cin>>s;
   for(int i=0;i<s.size();i++){
       if('0'<=s[i]&&s[i]<='9'){
          a[j]=s[i]-'0';
          j++;
       }
   }
   sort(a,a+j);
   for(int i=j-1;i>=0;i--){
      cout<<a[i];
   }
   return 0;
}
