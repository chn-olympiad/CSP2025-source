#include<bits/stdc++.h>
using namespace std;
string s;
int n;
string ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    for(int i=9;i>=0;i--){
        for(int j=1;j<=n;j++){
            if(s[j]-'0'==i){
                ans=ans+s[j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        cout<<ans[i];
    }
    return 0;
}
