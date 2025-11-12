#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
string s;
ll a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    ll j=0;
    for(ll i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    ll b[j];
    for(ll i=0;i<j;i++)
        b[i]=a[i];
    sort(b,b+j);
    for(ll i=j-1;i>=0;i--)
        cout<<b[i];
    return 0;
}
