#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[100000],c[10000],a=1,b=1;
    while(a!=0){
    cin>>s[a];
    a++;
    }
    for(int i=1;i<a;i++){
    if(s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||\
s[i]==9||s[i]==0){
       c[b]=s[i];
       b++;
       }
    }
    for(int i=1;i<b;i++){
        for(int j=i+1;j<b;j++){
            if(c[i]<c[j]){
               int d=c[i];
               c[i]=c[j];
               c[j]=c[i];
            }
        }
    }
    for(int i=1;i<b;i++){
    cout<<c[i]<<endl;
    }
    return 0;
}



