#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int t[10];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[int(s[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(t[i]){
            t[i]--;
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}