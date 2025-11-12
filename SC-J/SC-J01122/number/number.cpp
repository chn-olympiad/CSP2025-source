#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
vector<char>v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    for(char ch:s)if(isdigit(ch))
        v.push_back(ch);
    sort(v.begin(),v.end(),greater<char>());
    for(char ch:v)cout<<ch;
    cout<<'\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}