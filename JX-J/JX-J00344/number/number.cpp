#include<iostream>
using namespace std;
int a[1000005];
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   string s;
   cin>>s;
   int n=s.size();
   for(int i=0;i<n;i++){
       if(s[i]>='0'&&s[i]<='9'){
           a[s[i]-'0']++;
       }
   }
   for(int j=9;j>=0;j--){
       while(a[j]--){
           cout<<j;
       }
   }
}
