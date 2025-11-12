#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int f=0;
    int d[100];
    int h=s.size();
    for(int i=0;i<=h;i++){
        if(s[i]=1) d[i]=s[i];
        if(s[i]=2) d[i]=s[i];
        if(s[i]=3) d[i]=s[i];
        if(s[i]=4) d[i]=s[i];
        if(s[i]=5) d[i]=s[i];
        if(s[i]=6) d[i]=s[i];
        if(s[i]=7) d[i]=s[i];
        if(s[i]=8) d[i]=s[i];
        if(s[i]=9) d[i]=s[i];
        if(s[i]=0) d[i]=s[i];
    }
    for(int i=0;i<=9;i++){
        cout<<d[i]<<endl;
    }
    return 0;
}
