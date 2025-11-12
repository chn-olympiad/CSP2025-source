#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 11;
long long lt[M];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(ll i=0;i<M;i++) lt[i] = 0;
    for(ll i=0;i<s.size();i++){
        ll o=s[i] - '0';
        if(o>=0 && o<=9) lt[o] ++;
    }
    for(ll i=9;i>=0;i--){
        for(ll j=0;j<lt[i];j++){
            cout<<i;
        }
    }
}
