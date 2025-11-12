#include<bits/stdc++.h>
using namespace std;
char s[1000000];
char c[1000];
int a[1000];
int k,b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<1000000;i++){
        if(s[i]>='0' && s[i]<='9'){
            c[k]=s[i];
            k++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='9'){
            a[b]=9;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='8'){
            a[b]=8;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='7'){
            a[b]=7;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='6'){
            a[b]=6;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='5'){
            a[b]=5;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='4'){
            a[b]=4;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='3'){
            a[b]=3;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='2'){
            a[b]=2;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='1'){
            a[b]=1;
            b++;
        }
    }
    for(int j=0;j<1000;j++){
        if(c[j]=='0'){
            a[b]=0;
            b++;
        }
    }
    for(int i=0;i<b;i++){
        cout<<a[i];
    }
    return 0;
}
