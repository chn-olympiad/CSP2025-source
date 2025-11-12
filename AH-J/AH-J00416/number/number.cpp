#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int t[15];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int l;
    l = s.size();
    for(int i = 0;i<l;i++){
        if(s[i]>='0' && s[i]<='9'){
            t[s[i]-'0']++;
        }
    }
    for(int i = 9;i>=0;i--){
        while(t[i]){
            cout<<i;
            t[i]--;
        }
    }
    cout<<"\n";
    return 0;
}
