#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s=stdin,t;
    //cin>>s;
    int a,b=0,c;
    a=s.size();
    for(int i=0;i<a;i++){
        if(s[i]>=48&&s[i]<=57){
            t[b]=s[i];
            b+=1;
        }
    }

    int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
    for(int i=0;i<b;i++){

        if(t[i]==48){
            n0+=1;
        }
        if(t[i]==49){
            n1+=1;
        }
        else if(t[i]==50){
            n2+=1;
        }
        else if(t[i]==51){
            n3+=1;
        }
        else if(t[i]==52){
            n4+=1;
        }
        else if(t[i]==53){
            n5+=1;
        }
        else if(t[i]==54){
            n6+=1;
        }
        else if(t[i]==55){
            n7+=1;
        }
        else if(t[i]==56){
            n8+=1;
        }
        else {
            n9+=1;
        }
    }
        for(int i=0;i<n9;i++){
            cout<<"9";
        }
        for(int i=0;i<n8;i++){
            cout<<"8";
        }
        for(int i=0;i<n7;i++){
            cout<<"7";
        }
        for(int i=0;i<n6;i++){
            cout<<"6";
        }
        for(int i=0;i<n5;i++){
            cout<<"5";
        }
        for(int i=0;i<n4;i++){
            cout<<"4";
        }
        for(int i=0;i<n3;i++){
            cout<<"3";
        }
        for(int i=0;i<n2;i++){
            cout<<"2";
        }
        for(int i=0;i<n1;i++){
            cout<<"1";
        }
        for(int i=0;i<n0;i++){
            cout<<"0";
        }
}

