#include<bits/stdc++.h>
using namespace std;
int ans[105];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);

long long a;
cin>>a;
long long a1=a;
int len=0;
while(a1>0){
   len++;
  a1=a1/10;
}
cout<<len<<endl;
for(int i=1;i<=len;i++){
    ans[a%10]++;
  a/=10;
}
for(int i=15;i>=1;i--){
   for(int j=1;j<=ans[i];j++){
       cout<<i;
    }
}
return 0;
}
