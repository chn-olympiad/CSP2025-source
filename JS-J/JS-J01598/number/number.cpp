#include<bits/stdc++.h>
using namespace std;
string s,ans="";
long long z,n[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    z=s.size();
    for(int i=0;i<z;i++){
        if(s[i]<='9' && s[i]>='0'){
            n[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(n[i]--)ans+= i+'0';
    }
    cout << ans;
    return 0;
}
