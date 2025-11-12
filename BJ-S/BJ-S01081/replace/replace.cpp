#include<iostream>
#include<string>
#include<map>
using namespace std;
multimap<string,string>s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        string s1,s2;
        cin>>s1>>s2;
        s.insert(make_pair(s1,s2));
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        for(auto it:s)
        {
            if(t1.find(it.first)==t1.npos)
            {
                continue;
            }
            int tmp=t1.find(it.first);
            string x=t1.substr(0,tmp),z=t1.substr(tmp+it.first.size(),t1.size()-tmp+it.first.size()-1);
            x+=it.second;
            x+=z;
            if(x==t2)
            {
                ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
