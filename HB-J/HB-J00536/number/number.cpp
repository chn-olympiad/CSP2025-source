#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[1005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    s='0'+s;
    for(int i=1;i<=n;i++){
        a[s[i]]++;
    }
    for(char i='9';i>='0';i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}