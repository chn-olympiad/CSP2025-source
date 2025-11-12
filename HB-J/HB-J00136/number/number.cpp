#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
