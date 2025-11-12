#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c[n+1];
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<s.length();i++) {
        if(s[i]=='0'){
            cout<<0;
            return 0;
        }
    }
    long long ans=1;
    for(int i=n;i>=1;i--) ans*=i;
    cout<<ans;
    return 0;
}
