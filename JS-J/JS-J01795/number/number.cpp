#include<bits/stdc++.h>
using namespace std;
//look out freopen!
string s;
int t[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(isdigit(s[i])){
            t[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(t[i]!=0){
            for(int j=1;j<=t[i];j++){
                cout<<i;
            }
        }
    }


    return 0;
}
