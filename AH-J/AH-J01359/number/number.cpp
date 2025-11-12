#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c['9'+100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0,f=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            c[s[i]]++;
        }
    }
    for(int i='9';i>='0';i--){
        for(int j=1;j<=c[i];j++){
            cout<<char(i);
        }
    }
return 0;}
