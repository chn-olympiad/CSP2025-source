#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>a;
int maxn=100005;
int mod=1e9+7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a.push_back(s[i]-'0');
        }
    }
    sort(a.begin(),a.end(),greater<int>());
    bool f=true;
    for(auto v : a)
    {
        if(v==0&&f)continue;
        else{
            f=false;
            cout<<v;
        }
    }
    if(f)cout<<0;
    return 0;
}
