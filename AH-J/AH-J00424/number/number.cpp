#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(LL i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(LL i=9;i>=0;i--){
        for(LL j=1;j<=a[i];j++) printf("%lld",i);
    }
    return 0;
}
