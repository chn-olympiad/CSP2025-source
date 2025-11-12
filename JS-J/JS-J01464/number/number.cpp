#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
     string s[1000007];
     string s1;
     int j=0;
     cin>>s1;
     for(int i=0;i<s1.length();i++){
        if(s1[i]>='0'&&s1[i]<='9'){
               s[j]=s1[i];
               j++;
               }
     }
     sort(s,s+j);

     return 0;
    }
