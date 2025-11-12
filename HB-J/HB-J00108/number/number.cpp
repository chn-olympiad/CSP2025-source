#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
string s;
int shu[10]={0},cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            shu[(int)s[i]-'0']++;
        }
    }
    for (int i=9;i>=0;i--){
        if(i==0 and cnt==0){
            cout<<0;
            return 0;
        }
        cnt+=shu[i];
        for (int j=1;j<=shu[i];j++) cout<<i;
    }
    return 0;
}