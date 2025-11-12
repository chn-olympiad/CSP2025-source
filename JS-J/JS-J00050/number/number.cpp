#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
int t[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[++t[0]]=s[i]-'0';
        }
    }
    sort(t+1,t+1+t[0]);
    for(int i=t[0]; i>=1; i--) cout<<t[i];
    return 0;
}
