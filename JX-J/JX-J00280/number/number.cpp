#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    long long m[1000001]={},n=0,w=0,e=0;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(a[i]==49){
            m[i]=1;
        }
        if(a[i]==50){
            m[i]=2;
        }
        if(a[i]==51){
            m[i]=3;
        }
        if(a[i]==52){
            m[i]=4;
        }
        if(a[i]==53){
            m[i]=5;
        }
        if(a[i]==54){
            m[i]=6;
        }
        if(a[i]==55){
            m[i]=7;
        }
        if(a[i]==56){
            m[i]=8;
        }
        if(a[i]==57){
            m[i]=9;
        }
        n++;
        if(a[i]>57){
            w++;
        }
    }
    if(n>=2){
        sort(m,m+n);
        for(int i=n-1;i>=w;i--){
            cout<<m[i];
        }
    }
   if(n==1){
        for(int i=0;i<n;i++){
            cout<<m[i];
        }
    }
    return 0;
}
