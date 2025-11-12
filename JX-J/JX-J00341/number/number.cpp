#include<bits/stdc++.h>
using namespace std;
string s;
int l;
int a[1000005];
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin>>s;
   for(int i=0;i<=s.size()-1;i++){
     if(s[i]>='0'&&s[i]<='9'){
        l++;
        a[l]=s[i]-'0';

     }
   }
   sort(a+1,a+l+1);
   for(int i=l;i>=1;i--){
       cout<<a[i];

   }



    return 0;
}
