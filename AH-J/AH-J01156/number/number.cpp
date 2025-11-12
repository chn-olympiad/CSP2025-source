#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll t=1,a[1000005];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[t]=s[i]-'0';
            t++;
        }
    }
    sort(a+1,a+t,cmp);
    for(ll i=1;i<t;i++){
        cout<<a[i];
    }
    return 0;
}
