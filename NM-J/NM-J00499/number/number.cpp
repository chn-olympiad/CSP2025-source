#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            a.push_back(0);
        }
        if(s[i]=='1')
        {
            a.push_back(1);
        }
        if(s[i]=='2')
        {
            a.push_back(2);
        }
        if(s[i]=='3')
        {
            a.push_back(3);
        }
        if(s[i]=='4')
        {
            a.push_back(4);
        }
        if(s[i]=='5')
        {
            a.push_back(5);
        }
        if(s[i]=='6')
        {
            a.push_back(6);
        }
        if(s[i]=='7')
        {
            a.push_back(7);
        }
        if(s[i]=='8')
        {
            a.push_back(8);
        }
        if(s[i]=='9')
        {
            a.push_back(9);
        }
    }
    sort(a.begin(),a.end());
    for(int i=a.size()-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
