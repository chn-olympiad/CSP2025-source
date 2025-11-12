#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in" , "r" , stdin);
    string s,str;
    getline(cin,s);
    int x=0,a[s.size()],sum=0,sum2,y=0,max=0;
    char p='0',q='9';
    for(int i=0;i<s.size();i++){
            a[i]=0;
        if(s[i]<=q && s[i] >=p){
            a[x]=s[i]-48;
            x++;
          }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){

            if(a[j]<=a[j+1]){
                sum=a[j];
                a[j]=a[j+1];
                a[j+1]=sum;
            }
        }
    }
    for(int j=0;j<x;j++){

            cout<<a[j];
        }

    return 0;
    freopen("number.out","w",stdout);
}
