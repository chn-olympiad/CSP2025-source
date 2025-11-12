#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    s.resize(1e6);cin>>s;
    int HASH[10]={};
    for(int i=0;i<s.size();i++){
        HASH[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(HASH[i]--)cout<<i;
    }
    fclose(stdin);fclose(stdout);
}