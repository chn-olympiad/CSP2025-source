
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
vector<int> ans;
bool cmp(int a,int b)
{

    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans.push_back(s[i]-'0');

        }

    }
    sort(ans.begin(),ans.end(),cmp);
    for(auto i:ans)
    {


        cout<<i;
    }
    return 0;
}
