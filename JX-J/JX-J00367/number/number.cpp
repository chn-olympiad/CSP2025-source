#include<bits/stdc++.h>
using namespace std;
#define LL long long
int t[15];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a=s.length();
    for(int i=0;i<a;i++){
        if(!isdigit(s[i]))continue;
        t[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(t[i]--){
            cout<<i;
        }
    }
    return 0;
}
