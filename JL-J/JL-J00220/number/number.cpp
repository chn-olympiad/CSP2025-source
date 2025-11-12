#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int flag=1;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='9'){
            cout<<s[i];
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='8'){
            cout<<s[i];
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='7'){
            cout<<s[i];
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='6'){
            cout<<s[i];
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='5'){
            cout<<s[i];
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='4'){
            cout<<s[i];
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='3'){
            cout<<s[i];
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='2'){
            cout<<s[i];
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cout<<s[i];
            flag=0;
        }
    }
    if(flag){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cout<<s[i];

        }
    }


    return 0;
}
