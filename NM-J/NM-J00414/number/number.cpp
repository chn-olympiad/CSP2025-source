#include <bits/stdc++.h>
using namespace std;
string s;
int number[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++)if(s[i]-'0'<=10&&s[i]-'0'>=0)number[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=number[i];j++)cout<<i;
    return 0;
}
