#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>v;
    int l=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            v.push_back(s[i]-'0');
            l++;
        }
    }
    sort(v.begin(),v.end());
    for(int i=l-1;i>=0;i--)
    {
        printf("%d",v[i]);
    }
    return 0;
}
