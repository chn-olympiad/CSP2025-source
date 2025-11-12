#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mp[20];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            mp[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        int t=mp[i];
        while(t--) cout<<i;
    }
    return 0;
}
