#include<bits/stdc++.h>
using namespace std;
string s;
int b[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            b[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(b[i]>0){
           while(b[i]--){
                cout<<i;
            }
        }
    }
}