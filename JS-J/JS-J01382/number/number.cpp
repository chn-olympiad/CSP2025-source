#include <bits/stdc++.h>
using namespace std;
int T[15];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            T[str[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=T[i];j++){
            cout<<i;
        }
    }
    return 0;
}
