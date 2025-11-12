#include<bits/stdc++.h>
using namespace std;
long long cnt[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0')cnt[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(cnt[i]>0){
            cnt[i]--;
            cout<<(char)(i+'0');
        }
    }
    return 0;
}
