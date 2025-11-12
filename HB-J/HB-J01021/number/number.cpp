#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6;
int a[N];
int main(){
      //freeopen("number.in","r",stdin);
      //freeopen("number.out","w",stdout);
      cin>>s;
      int num=1;
      for(int i=0;i<s.size();i++){
          if(s[i]=='0') {
             a[num]=0;
             num++;
          }
          if(s[i]=='1') {
             a[num]=1;
             num++;
          }
          if(s[i]=='2') {
             a[num]=2;
             num++;
          }
          if(s[i]=='3') {
             a[num]=3;
             num++;
          }
          if(s[i]=='4') {
             a[num]=4;
             num++;
          }
          if(s[i]=='5') {
             a[num]=5;
             num++;
          }
          if(s[i]=='6') {
             a[num]=6;
             num++;
          }
          if(s[i]=='7') {
             a[num]=7;
             num++;
          }
          if(s[i]=='8') {
             a[num]=8;
             num++;
          }
          if(s[i]=='9') {
             a[num]=9;
             num++;
          }
          else continue;
      }
      sort(a+1,a+1+num);
      for(int i=num;i>=2;i--){
           cout<<a[i];
      }
      return 0;
}
