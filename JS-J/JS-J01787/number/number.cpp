#include<iostream>
using namespace std;
int bu[10];
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  string s;cin>>s;
  for(int j=0;j<(int)s.size();j++){
    if(s[j]>='0' && s[j]<='9'){
        bu[s[j]-48]++;
    }
  }
  for(int j=9;j>=0;j--){
    for(int k=0;k<bu[j];k++){
        cout<<j;
    }
  }
  return 0;
}
