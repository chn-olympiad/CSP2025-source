#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
string s;
int Hash[N+10];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9') Hash[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=Hash[i];j++) cout<<i;
    cout<<"\n";
    return 0;
}