#include<bits/stdc++.h>
using namespace std;
string str;
int t[10];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("number.in","r",stdin),freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();++i){
        if(str[i]>='0' && str[i]<='9') t[str[i]-'0']++;
    }
    for(int i=9;i>=0;--i){
        while(t[i]){cout<<i;t[i]--;}
    }
    return 0;
}