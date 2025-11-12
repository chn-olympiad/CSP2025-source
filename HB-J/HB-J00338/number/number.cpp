#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[1000005]={};
    char b[1000005]={};
    char c[1000005]={};
    string s;
    cin>>s;
    int x=0,y=0;
    for(int i=0;i<s.size();i++){
        a[i]=s[i];
        if(a[i]>='0'&&a[i]<='9'){
            b[x]=a[i];
            x++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='9'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='8'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='7'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='6'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='5'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='4'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='3'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='2'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='1'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<x;i++){
        if(b[i]=='0'){
            c[y]=b[i];
            y++;
        }
    }
    for(int i=0;i<y;i++){
        cout<<c[i];
    }
    return 0;
}
