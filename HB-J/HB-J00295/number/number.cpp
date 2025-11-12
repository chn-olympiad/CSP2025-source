#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ans[N]; string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s; int cnt=0;
    for(int i=0;i<s.size();++i){
        if(s[i]>='0'&&s[i]<='9') ans[++cnt]=s[i]-'0';
    }
    sort(ans+1,ans+1+cnt);
    for(int i=cnt;i>=1;--i) cout<<ans[i];
    return 0;
}