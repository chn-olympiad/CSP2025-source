#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
string s,ans;
int a[114];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.length();i++){
        if(s[i]>=48&&s[i]<=57){
            a[s[i]-48]++;
        }
    }
    for(int i=9;i>=1;i--){
        for(int j=1;j<=a[i];j++){
            ans+=i+48;
        }
    }
    if(ans==""){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=a[0];i++)ans+='0';
    cout<<ans;
    return 0;
}
