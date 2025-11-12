#include<bits/stdc++.h>
using namespace std;
int cnt[15];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(isdigit(s[i]))cnt[s[i]-'0']++;
    }
    bool f=1;
    for(int i=9;i>=0;i--){
        if(cnt[i]!=0)f=0;
        for(int j=1;j<=cnt[i];j++){
            cout<<i;
        }
    }
    return 0;
}
