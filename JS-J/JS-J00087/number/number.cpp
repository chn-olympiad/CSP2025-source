#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    string s;
    cin>>s;
   int n=s.size(),number;
   for(int i=0;i<n;i++){
    if(s[i]>='0'&&s[i]<='9'){
    number=(int)(s[i]);
    a[number]++;
    }
   }
   for(int i=9;i>=0;i--){
   while(a[i]!=0)
    cout<<i;
   }
 return 0;
}
