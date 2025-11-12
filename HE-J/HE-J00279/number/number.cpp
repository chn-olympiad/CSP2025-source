#include<iostream>
#include<string>
using namespace std;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    char a[9]={s};
    int sum=0;
    for(int i=0;i<9;i++){
        if(a[i]=='9'){
            cout<<a[i];
        }
    }
    for(int i=0;i<9;i++){
        if(a[i]=='8'){
            cout<<a[i];
        }
    }
    for(int i=0;i<9;i++){
        if(a[i]=='7'){
            cout<<a[i];
        }
    }
    for(int i=0;i<9;i++){
        if(a[i]=='6'){
            cout<<a[i];
        }
    }
    for(int i=0;i<9;i++){
        if(a[i]=='5'){
            cout<<a[i];
        }
    }
    for(int i=0;i<9;i++){
        if(a[i]=='4'){
            cout<<a[i];
        }
    }
    for(int i=0;i<9;i++){
        if(a[i]=='3'){
            cout<<a[i];
        }
    }
    for(int i=0;i<9;i++){
        if(a[i]=='2'){
            cout<<a[i];
        }
    }
    for(int i=0;i<9;i++){
        if(a[i]=='1'){
            cout<<a[i];
        }
    }
    return 0;
}
