#include<bits/stdc++.h>
#include<bits/stl_algo.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=1e6+5;
string s;
vector<int> ans;
bool cmp(int x,int y){return x>y;}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for (int i=0;i<s.size();i++){
        if (isdigit(s[i]))ans.push_back(s[i]-'0');
    }
    sort(ans.begin(),ans.end(),cmp);
    for (auto i:ans)cout<<i;
    return 0;
}
