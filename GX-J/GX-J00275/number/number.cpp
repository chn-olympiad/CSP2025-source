#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,m;
    long long numbers[100001],i=0,j=0,k=0,gf[11];
    getline(cin,s);
    cout<<s;
    j=0;
    for(i=0;i<11;i++){
        gf[i]=0;
    }
    for(i=0;s[i]!='\0';i++){
        if('9'>=s[i] && s[i]>='0'){
            numbers[j]=s[i]-'0';
            j++;
        }
    }
    for(i=0;i<j;i++){
        gf[numbers[i]]++;
    }

    j=0;
    for(i=10;i>-1;i--){
        for(k=0;k<gf[i];k++){
            m[j]=i+'0';
            j++;
        }

    }
    for(i=0;i<j;i++){
        cout<<m[i];
    }
    /*
     for(i=j-1;i>=0;i--){
            cout<<m[i]<<endl;;
    }
    */
    return 0;
}


