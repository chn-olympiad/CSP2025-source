#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp(int x,int y){return x>y;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<int(s.size());i++)
        if (s[i]>='0' && s[i]<='9') v.push_back(s[i]-'0');
    sort(v.begin(),v.end(),cmp);
    for (auto i:v) cout<<i;
    return 0;
}

// I love CCF forever
// Please give me the scores of 100 pap
