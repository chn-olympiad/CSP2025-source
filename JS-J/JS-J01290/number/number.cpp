#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[1100000];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    ll id=0;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            id++;
            a[id]=s[i]-'0';
        }
    }
    sort(a+1,a+id+1);
    for(ll i=id;i>=1;i--){
        cout<<a[i];
    }

    return 0;
}
