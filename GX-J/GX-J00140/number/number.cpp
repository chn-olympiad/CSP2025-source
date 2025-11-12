#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    freopen("number.in","r","stdin");
    freopen("number.out","w","stdout");
    string a[1000005],b,c;
    int i=1;
    while(cin>>b){
        if(b=="0"||b=="1"||b=="2"||b=="3"||b=="4"||b=="5"||b=="6"||b=="7"||b=="8"||b=="9"){
            a[i]=b;
        }
        i++;
    }for(int m=1;m<=i;m++){
        for(int n=2;n<=i;n++){
            if(a[n]>a[n-1]){
                c=a[n-1];
                a[n-1]=a[n];
                a[n]=c;
            }
        }
    }
    for(int m=1;m<=i;m++){
        cout<<a[m];
    }
    return 0;
    }
