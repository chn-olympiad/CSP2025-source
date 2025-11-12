#include <bits/stdc++.h>
using namespace std;
string s;
vector <int> v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (char i:s) if (i>='0'&&i<='9') v.push_back(i-'0');
    sort(v.begin(),v.end(),greater<int>());
    for (int i:v) cout<<i;
    return 0;
}
