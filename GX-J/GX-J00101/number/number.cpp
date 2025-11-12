#include<bits/stdc++.h>
using namespace std;
string s;
int b=1;
bool cmp(int x,int y)
{
    return x>y;
}
vector<char> v;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {

        if(s[i]>='0'&&s[i]<='9')
        {
            v.push_back(s[i]);
            b++;
        }
    }
    sort(v.begin(),v.begin()+b,cmp);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    return 0;
}
