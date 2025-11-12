#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b){return a>b;}
vector<int>v;
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    for(int i=0;i<s.size();++i)if(isdigit(s[i]))v.push_back(s[i]-'0');
    sort(v.begin(),v.end(),cmp);
    for(auto&i:v)cout<<i;
    return 0;
}
