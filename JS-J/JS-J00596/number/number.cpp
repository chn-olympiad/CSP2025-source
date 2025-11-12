#include <bits/stdc++.h>
using namespace std;
string str;
vector<int> vec;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>str;
    for(auto ch:str) if(isdigit(ch)) vec.push_back(ch-'0');
    sort(vec.begin(),vec.end(),greater<int>());
    for(auto i:vec) cout<<i;
    cout<<endl;
    return 0;
}
