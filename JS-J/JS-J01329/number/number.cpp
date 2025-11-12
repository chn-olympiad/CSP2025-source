#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int b[20]={0};
    string s;
    cin>>s;
    for(int i=0;i<=s.length();i++){
        if('0'<=s[i]&&s[i]<='9'){
            b[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
