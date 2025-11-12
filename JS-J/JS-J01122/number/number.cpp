#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int>vec;
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>s;
    for(int i = 0;i < s.size();i++)if(s[i] >= '0' && s[i] <= '9')vec.push_back(s[i] - '0');
    sort(vec.begin(), vec.end(), greater<int>());
    for(int i = 0;i < vec.size();i++)cout<<vec[i];
}
