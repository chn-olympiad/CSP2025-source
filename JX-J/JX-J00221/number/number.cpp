#include<bits/stdc++.h>
using namespace std;
string s;
int n[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int u=s[i]-'0';
            n[u]++;
        }
    }
    for(int i=10;i>=0;i--){
        for(int j=0;j<n[i];j++)
            cout<<i;
    }
    return 0;
}
