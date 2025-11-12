#include <bits/stdc++.h>
using namespace std;
int n,a[1000001],sum;
string s;
int main(){
 //freopen("number.in","r",stdin);
 //freopen("number.out","w",stdout);
 cin>>s;
 n=s.length();
 for(int i=0;i<n;i++)
 if(s[i]>='0'&&s[i]<='9'){
  sum++;
  a[sum]=s[i]-'0';
 }
 for(int i=9;i>=0;i--){
  for(int j=1;j<=sum;j++)
   if(a[j]==i)cout<<i;
 }
 return 0;
}
