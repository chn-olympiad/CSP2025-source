#include<bits/stdc++.h>
using namespace std;
struct node
{
    string s;
    int pos;
}s1[200010],s2[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i].s>>s2[i].s;
        s1[i].pos=s1[i].s.find('b');
        s2[i].pos=s2[i].s.find('b');
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        int x=t1.find('b'),y=t2.find('b');
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(y-x==s2[i].pos-s1[i].pos&&s1[i].s.size()-s1[i].pos<=t1.size()-x)
                ans++;
        }
        cout<<ans;
    }
    return 0;
}
