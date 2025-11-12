#include<bits/stdc++.h>
using namespace std;
long long cnt[300];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(isdigit(s[i])){
            cnt[s[i]]++;
        }
    }
    for(char i='9';i>='0';i--){
        if(cnt[i]){
            for(long long j=1;j<=cnt[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
