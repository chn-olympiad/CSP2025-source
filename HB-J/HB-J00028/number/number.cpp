#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long bot[10]={0};
    cin>>s;
    for(int i=0;i<=s.size();i++)
        if(s[i]<='9'&&s[i]>='0')
            bot[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=0;j<bot[i];j++)
            cout<<i;
    return 0;
}
