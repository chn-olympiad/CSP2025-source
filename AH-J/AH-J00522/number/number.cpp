#include<bits/stdc++.h>
using namespace std;
int t[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[s[i]-'0']++;
        }
    }for(int i=9;i>=0;i--){
        for(int j=1;j<=t[i];j++){
            cout<<i;
        }
    }
    return 0;
}
