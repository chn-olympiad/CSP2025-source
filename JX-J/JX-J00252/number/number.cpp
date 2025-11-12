#include<bits/stdc++.h>
using namespace std;
long long a[1001]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
   // cout<<s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            a[s[i]-'0']++;
           // cout<<a[s[i]-'0']<<" "<<int(s[i]);
        }
    }
    for(int i=9;i>=0;i--){
      //  cout<<a[i];
      if(a[i]>0){
            for(int j=0;j<a[i];j++){
                 cout<<i;
            }
      }
    }
    return 0;
}
