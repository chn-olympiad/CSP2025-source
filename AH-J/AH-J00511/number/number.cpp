#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[20];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    int len=s.length();
  
    for(int i=0;i<len;i++){
        if(s[i]<='9'&&s[i]>='0'){
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















//#Shang4Shan3Ruo6Shui4
