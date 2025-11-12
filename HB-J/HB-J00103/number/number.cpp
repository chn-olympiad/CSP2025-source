#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
string s;
long long n,ans,a[1000005];
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
   cin>>s;
   n=s.size();
   For(i,0,n-1){
   if(s[i]=='9'){
    ans++;
    a[ans]=9;
   }else if(s[i]=='8'){
    ans++;
    a[ans]=8;
   }else if(s[i]=='7'){
    ans++;
    a[ans]=7;
   }else if(s[i]=='6'){
    ans++;
    a[ans]=6;
   }else if(s[i]=='5'){
    ans++;
    a[ans]=5;
   }else if(s[i]=='4'){
    ans++;
    a[ans]=4;
   }else if(s[i]=='3'){
    ans++;
    a[ans]=3;
   }else if(s[i]=='2'){
    ans++;
    a[ans]=2;
   }else if(s[i]=='1'){
    ans++;
    a[ans]=1;
   }else if(s[i]=='0'){
   ans++;
    a[ans]=0;
   }
   }
   sort(a+1,a+1+ans);
   Rep(i,ans,1)printf("%lld",a[i]);
  return 0;
}
