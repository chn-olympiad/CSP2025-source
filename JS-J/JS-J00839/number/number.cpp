#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   const long long n=1000000;
   string s;
   cin>>s;
   char c[n+3]={'0'};
   int top=1;
   for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
         c[top]=s[i];
         top++;
    }
   }
   sort(c+1,c+n+1);
   for(int j=n+1;j>n-top+1;j--){
     cout<<c[j];
   }
   return 0;
}

