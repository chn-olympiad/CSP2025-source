#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
long long M=998244353,ans=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            cout<<1;
            return 0;
        }
    }
    for(int i=n;i>=1;i--){
        ans=ans*i%M;
    }
    cout<<ans;
    return 0;
}
