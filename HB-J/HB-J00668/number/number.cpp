#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    vector<int>k;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        if('0'<=s[i]&&s[i]<='9')k.push_back(s[i]-'0');
    }
    int kl=k.size();
    sort(k.begin(),k.end(),cmp);
    for(int i=0;i<k.size();i++)
    {
        cout<<k[i];
    }
    return 0;
}