#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000006],cur;
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(ll i = 0;i<s.size();i++){
        if(isdigit(s[i])){
            a[++cur] = s[i]-'0';
        }
    }
    sort(a+1,a+cur+1,cmp);
    if(a[1]==0){
        cout<<0;
        return 0;
    }
    for(ll i = 1;i<=cur;i++){
        cout<<a[i];
    }
    return 0;
}
