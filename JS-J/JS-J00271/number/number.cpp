#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000001],k;
bool cmp(int a,int b){
    return a>b;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin>>a;
   for(int i=0;i<a.size();i++){
        if(a[i]-'0'>=0&&a[i]-'0'<=9)s[k++]=a[i]-'0';
   }
   sort(s,s+k,cmp);
   for(int i=0;i<k;i++){
        cout<<s[i];
   }
   return 0;
}
