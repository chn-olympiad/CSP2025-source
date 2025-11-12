#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010];
string s,s1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9'){
            s1+=s[i];
        }
    }
    sort(s1.begin(),s1.end());
    reverse(s1.begin(),s1.end());
    for(ll i=0;i<s1.size();i++){
        a[i+1]=s1[i]-'0';
    }
    for(ll i=1;i<=s1.size();i++){
        printf("%lld",a[i]);
    }
    return 0;
}


