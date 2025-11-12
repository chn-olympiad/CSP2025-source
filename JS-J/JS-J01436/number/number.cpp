#include <bits/stdc++.h>
using namespace std;
int ton[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
   string s;
   cin>>s;
   string ans;
   for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        ton[s[i]-'0']++;
     }
   }

    for(int i=9;i>=0;i--){
      while(ton[i]){
             ans+=i+'0';
             ton[i]--;
    }
   }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
