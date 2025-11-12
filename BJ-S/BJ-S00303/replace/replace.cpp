#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string>> v;
int n,q;
bool in(string a,string b)
{
    bool flag=0;
    size_t i=0;
    for(char c:b)
    {
        if(flag&&c!=a[i])return false;
        if(c==a[i++])flag=1;
        if(i==a.size()-1)break;
    }
    if(i!=a.size()-1)flag=0;
    return flag;
}
int main()
{
    cin.tie(nullptr);

    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        pair<string,string> p;
        cin>>p.first>>p.second;
        v.push_back(p);
    }
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        pair<string,string> target;
        cin>>target.first>>target.second;
        for(pair<string,string> p:v)
        {
            if(in(p.first,target.first)&&in(p.second,target.second)&&p.first.find(target.first[0])==p.second.find(target.second[0]))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
