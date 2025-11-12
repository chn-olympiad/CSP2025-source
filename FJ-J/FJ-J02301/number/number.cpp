#include<bits/stdc++.h>
using namespace std;
string s;
int a[11],cnt;
int main(){
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 cin>>s;
 for(int i=0;i<s.size();i++){
  if(s[i]<=57&&s[i]>=48){
   a[s[i]-48]+=1; cnt++;
  }
 } 
 for(int i=9;i>=0;i--){
  for(int j=1;j<=a[i];j++){
   cout<<i;
  }
 }
 return 0;
}