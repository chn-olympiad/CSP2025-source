#include<bits/stdc++.h>
using namespace std;
//g++ number.cpp -o number -O2 -Wall -Wextra
#define ll long long
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>v;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            v.push_back(s[i]-'0');
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    //cout<<endl;
    return 0;
}