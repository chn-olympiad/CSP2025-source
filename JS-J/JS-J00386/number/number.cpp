#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        int num=s[i]-'0';
        if(num>=0&&num<=9) v.push_back(num);
    }
    sort(v.begin(),v.end());
    int flag=1;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i]==0&&i==v.size()-1) flag=0;
        if(flag) cout<<v[i];
    }
    if(!flag) cout<<0;
    return 0;
}
