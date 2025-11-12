#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll cnt[10];
string ans;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if('0'<=s[i] && s[i]<='9')
            cnt[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        if (cnt[i]){
            //cout<<i<<' '<<cnt[i]<<endl;
            for(int j=0;j<cnt[i];j++)
                ans+=('0'+i);
        }
    cout<<ans;
    return 0;
}
