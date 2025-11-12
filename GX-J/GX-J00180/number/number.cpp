#include <bits/stdc++.h>
using namespace std;
string s;
long long su=0;
int n[1000005]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            su++;
            n[i]=s[i]-'0';

        }
    }
    //for(int i=0;i<s.length();i++){
    //    for(int j=i;j<s.length();j++){
    //        if(n[j]<n[j+1])swap(n[j],n[j+1]);
    //    }
    //}
    sort(n,n+s.length());
    long long en=s.length()-su;
    for(int i=s.length()-1;i>=en;i--)cout<<n[i];
    return 0;
}
