#include<bits/stdc++.h>
using namespace std;
string s;
int x[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int a=s.size();
    for(int i=0;i<a;i++){
        if(s[i]>='0'&&s[i]<='9') x[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int k=0;k<x[i];k++) cout<<i;
    }
    return 0;
}
