#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005];
int b;
int sum=0,ans=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
  cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
        sum++;
       }
       if(s[i]=='1'){
        a[i]=1;
        ans++;
       }
       if(s[i]=='2'){
        a[i]=2;
       ans++;
       }
       if(s[i]=='3'){
        a[i]=3;
        ans++;
       }
       if(s[i]=='4'){
        a[i]=4;
       ans++;
       }
       if(s[i]=='5'){
        a[i]=5;
       ans++;
       }
       if(s[i]=='6'){
        a[i]=6;
        ans++;
       }
       if(s[i]=='7'){
        a[i]=7;
       ans++;
       }
       if(s[i]=='8'){
        a[i]=8;
        ans++;
        }
       if(s[i]=='9'){
        a[i]=9;
       ans++;

       }
    }
for(int j=1;j<s.size();j++){
    if(a[j-1]<a[j]){
        b=a[j-1];
        a[j-1]=a[j];
        a[j]=b;
    }
}

for(int j=0;j<s.size();j++){
    if(a[j]<a[j+1]){
        b=a[j+1];
        a[j+1]=a[j];
        a[j]=b;
    }

}
for(int k=0;k<s.size();k++){
   if(a[k]==0){
    break;
   }
    cout<<a[k];
}
for(int h=0;h<sum-1;h++){
    cout<<0;
}
    return 0;
}
