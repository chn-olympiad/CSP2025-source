#include<bits/stdc++.h>
using namespace std;
char s[300005];
int b[300005];
bool cmp(int a,int b){
  return a>b;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin >> s;
   int num=0;
   int lens=strlen(s);
   for(int i=0;i<lens;i++){
   if(s[i]-'0'>=0 && s[i]-'0'<=9){
   b[num]=s[i]-'0';
   num++;
       }
   }
   sort(b,b+num-1,cmp);
   for(int i=0;i<=num;i++){
      cout<<b[i++];
   }
   return 0;
}
