#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    ll len=s.size();
    for(int i=0;i<len;i++){
        if(isdigit(s[i])){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
