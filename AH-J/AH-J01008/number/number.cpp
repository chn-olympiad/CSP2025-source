#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL cnt[100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'){
            cnt[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++){
            printf("%lld",i);
        }
    }
    return 0;
}
