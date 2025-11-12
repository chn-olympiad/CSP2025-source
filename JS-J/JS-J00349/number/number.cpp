#include<bits/stdc++.h>
using namespace std;
string s;
char ans[3000000];
int l=0;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.out","w",stdout);
    freopen("number.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9')ans[l++]=s[i];
    }
   // cout<<ans;
    sort(ans,ans+l,cmp);
    cout<<ans;
    return 0;;
}
/*
I love luogu

CCF
CSP
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++


*/
