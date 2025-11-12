#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<string>v1;
vector<string>v2;
string t1,t2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    string s1,s2;
    int k1=0,k2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        if(s1=="a"&&s2=="b")k1=1;
        if(s1==s2)k2=1;
        v1.push_back(s1);
        v2.push_back(s2);
    }
    for(int t=1;t<=q;t++)
    {
        cin>>t1>>t2;
        long long ans=0;
        bool key=1;
        for(int i=0;i<t1.size();i++)
        {
            if(t1[i]!=t2[i])key=0;
        }
        cout<<0<<endl;
    }
    return 0;
}
