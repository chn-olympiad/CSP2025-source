#include<bits/stdc++.h>
using namespace std;
int s[100001];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b=0;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]<='9'&&a[i]>='0'){
            if(a[i]=='1'){
                s[b]=1;
                b++;
            }
            if(a[i]=='2'){
                s[b]=2;
                b++;
            }
            if(a[i]=='3'){
                s[b]=3;
                b++;
            }
            if(a[i]=='4'){
                s[b]=4;
                b++;
            }
            if(a[i]=='5'){
                s[b]=5;
                b++;
            }
            if(a[i]=='6'){
                s[b]=6;
                b++;
            }
            if(a[i]=='7'){
                s[b]=7;
                b++;
            }
            if(a[i]=='8'){
                s[b]=8;
                b++;
            }
            if(a[i]=='9'){
                s[b]=9;
                b++;
            }
            if(a[i]=='0'){
                s[b]=0;
                b++;
            }
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==9){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==8){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==7){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==6){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==5){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==4){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==3){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==2){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==1){
            cout<<s[i];
        }
    }
    for(int i=0;i<b;i++){
        if(s[i]==0){
            cout<<s[i];
        }
    }/*
    sort(s+1,s+a.length()+1);
    for(int i=a.length()-1;i>=0;i--){
        cout<<s[i];
    }
    */
    return 0;
}
