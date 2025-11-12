#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int c[10]={0};
    cin>>s;
    s+=';';
    int i=0;
    while(s[i]!=';'){
        if(s[i]>='0'&&s[i]<='9'){
            c[s[i]-'0']++;
        }
        i++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<c[i];j++){
            cout<<i;
        }
    }
    return 0;
}
