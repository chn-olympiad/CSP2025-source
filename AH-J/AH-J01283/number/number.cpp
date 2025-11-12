#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
string s,t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sort(s.begin(),s.end());
    for(long long i=0;i<s.size();i++){
        if(isdigit(s[i])){
            t+=s[i];
        }else if(isalpha(s[i])){
            break;
        }
    }
    for(long long i=t.size()-1;i>=0;i--){
        cout<<t[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
