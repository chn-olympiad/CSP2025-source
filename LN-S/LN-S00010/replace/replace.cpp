#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
#define MN 200001
using ll = long long;
string s[MN][2];
ll n,q;
bool if1(string s1,string s2,ll l){
    if(s2.length()>s1.length()) return false;
    ll r=l+s2.length();
    for(ll i=l;i<r;i++) if(s1[i]!=s2[i-l]) return false;
    return true;
}
bool if2(string s1,string s2,string s3,ll l){
    int r=l+s2.length();
    for(ll i=l;i<r;i++) s1[i]=s2[i-l];
    for(ll i=0;i<s1.length();i++) if(s1[i]!=s3[i]) return false;
    return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(ll i=0;i<n;i++) cin>>s[i][0]>>s[i][1];
    while(q--){
        cout<<"*"<<endl;
        int cnt=0;
        string s1,s2;
        cin>>s1>>s2;
        for(ll i=0;i<n;i++){
            string t1=s[i][0],t2=s[i][1];
            if(if1(s1,t1,i)&&if2(s1,t2,s2,i)) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
