#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);ios::sync_with_stdio(0);
    string s;cin>>s;
    for(int i=0;i<(int)s.size();++i){
        if(s[i]>='0'&&s[i]<='9'){
            t[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;--i){
        for(int j=0;j<t[i];++j){
            cout<<i;
        }
    }cout<<'\n';
    return 0;
}