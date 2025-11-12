/*
zhe ti yi ding yao a a
bu a wo ma hui ma wo hen jiu
qiu ni le ...
*/
#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+7;
int d[N];
string s;
int idx;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
            d[++idx]=s[i]-'0';
    }
    sort(d+1,d+1+idx,greater<int>());
    for(int i=1;i<=idx;i++)
        cout << d[i];
    return 0;
}
