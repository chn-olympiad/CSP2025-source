#include<bits/stdc++.h>
using namespace std;
string a;
bool allzero=true;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int n=a.length();
    for(int i=0;i<n;i++){
        if(a[i]=='9'){
            cout<<a[i];
            allzero=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='8'){
            cout<<a[i];
            allzero=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='7'){
            cout<<a[i];
            allzero=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='6'){
            cout<<a[i];
            allzero=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='5'){
            cout<<a[i];
            allzero=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='4'){
            cout<<a[i];
            allzero=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='3'){
            cout<<a[i];
            allzero=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='2'){
            cout<<a[i];
            allzero=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            cout<<a[i];
            allzero=0;
        }
    }
    if(allzero){
        cout<<0;
        return 0;
    }


    for(int i=0;i<n;i++){
        if(a[i]=='0'){
            cout<<a[i];
            allzero=0;
        }
    }

    return 0;
}

//0zsa8s2
