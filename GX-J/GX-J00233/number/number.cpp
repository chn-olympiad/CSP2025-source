#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[10];
bool isnb(char x){return x>='0'&&x<='9';}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(isnb(s[i])){
            t[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=t[i];j++){
            cout<<i;
        }
    }
    return 0;
}
