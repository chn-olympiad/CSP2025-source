#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5;
string s;
ll t[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    ll j=1;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[j]=s[i]-'0';
            j++;
        }
    }
    sort(t+1,t+j+1);
    for(ll i=j;i>1;i--){
        cout<<t[i];
    }
    return 0;
}
