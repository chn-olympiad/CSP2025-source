#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int c[50];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            c[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(c[i]--){
            cout<<i;
        }
    }
    return 0;
}
