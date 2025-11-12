#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int ky[1000000],sw=0;
    cin>>s;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9'){
            ky[sw]=s[i]-'0';
            sw++;
        }
    }
    sw--;
    int t[10];
    for(int i=0;i<=sw;i++){
        t[ky[i]]++;
    }
    for(int i=9;i>=0;i--){
        for(int g=1;g<=t[i];g++){
            cout<<i;
        }
    }
    return 0;
}
