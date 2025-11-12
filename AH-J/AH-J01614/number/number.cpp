#include<string>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    string num;
    for(int i=0;i<s.length();i++){
        if(s[i]>47&&s[i]<58)num+=s[i];
    }
    sort(num.begin(),num.end(),greater<char>());
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
