#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+10;

string s;
int k[N],cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.length();i++) if(s[i]>='0' && s[i]<='9') k[++cnt]=s[i]-'0';
    sort(k+1,k+1+cnt,cmp);
    for(int i=1;i<=cnt;i++) cout<<k[i];

    return 0;
}