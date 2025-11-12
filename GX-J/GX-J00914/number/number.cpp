#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    vector<char> s;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')s.push_back(a[i]);
    }
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<s.size();i++)cout<<s[i];
    return  0;
}
