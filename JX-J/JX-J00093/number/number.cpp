#include <bits/stdc++.h>
using namespace std;

string s;
int t[11];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0; i<s.size(); i++){
       if(s[i]>='0'&&s[i]<='9'){
            t[int(s[i])-48]++;
        }
    }
    for(int i=9; i>=0; i--){
        for(;t[i]!=0;t[i]--){
            cout<<i;
        }
    }
    return 0;
}
