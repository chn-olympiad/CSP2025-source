#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int a[N]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    ll len=s.size();
    ll j=0;
    for(ll i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[j]=s[i]-48;
            j++;
        }
    }
    sort(a,a+j);
    for(int i=j-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
