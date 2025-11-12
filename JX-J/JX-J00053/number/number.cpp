#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    vector<int> num;

    string s; cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            num.push_back(s[i]-'0');
    }

    sort(num.begin(),num.end(),cmp);

    for(int i=0;i<num.size();i++)
    {
        cout<<num[i];
    }

    return 0;
}
