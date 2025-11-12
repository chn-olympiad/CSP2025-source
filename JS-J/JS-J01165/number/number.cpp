#include<bits/stdc++.h>
using namespace std;
string s;
long long n[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            n[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(n[i]--){
            cout<<i;
        }
    }
    return 0;
}
