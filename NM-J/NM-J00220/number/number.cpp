#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0,b[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.length();i++){
        a[i]=s[i];
        if(s[i]>=48 && s[i]<=57){
            ans++;
            b[ans]=s[i]-47;
        }
    }
    if(ans==1){
        cout<<b[1];
    }
    return 0;
}
