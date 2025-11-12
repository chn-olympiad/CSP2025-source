#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int n[100006],ni=0;
bool cmp(int x,int y){
    return x>y;
}
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            n[ni]=s[i]-'0';
            ni++;
        }
    }
    sort(n,n+ni,cmp);
    for(int i=0;i<ni;i++){
        cout<<n[i];
    }
    return 0;
}
