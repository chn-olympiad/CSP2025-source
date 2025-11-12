#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   string s;
   int a[10000]={0},b=0,c[15]={0};
   cin>>s;
   for(int i=0;i<=s.size();i++){
    if(s[i]>='0' && s[i]<='9'){
        a[b]=int(s[i]-'0');
        c[a[b]]++;
        b++;
    }
   }
   for(int i=9;i>=0;i--){
    if(c[i]>0){
        int x=c[i];
        while(x){
            cout<<i;
            x--;
        }
    }
   }
   return 0;
}
