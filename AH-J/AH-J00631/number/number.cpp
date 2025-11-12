#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL cnt[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string ans;
    string s;
    cin>>s;
    for(LL i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            LL x=s[i]-'0';
            cnt[x]++;
        }
    }
    for(LL ti=9;ti>=0;ti--){
        for(LL i=1;i<=cnt[ti];i++){
            ans+=(ti+'0');
        }
    }
    cout<<ans;
    return 0;
}
