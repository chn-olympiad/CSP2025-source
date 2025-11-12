#include<bits/stdc++.h>
using namespace std;
long long tot,a[1011111],cnt;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[++tot]=s[i]-'0';
            if(a[tot]==0){
                cnt++;
            }
        }
    }
    sort(a+1,a+tot+1);
    if(cnt==tot){
        cout<<0;
        return 0;
    }
    for(long long i=tot;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
