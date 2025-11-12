#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    string s1,s2;
}a[200001];
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i].s1>>a[i].s2;
    while(q--)
    {
        string s1,s2;
        cin>>s1>>s2;
        string t1=s1,t2=s2;
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            if(s1.size()!=s2.size())
                continue;
            int cur1=t1.find(a[j].s1),cur2=t2.find(a[j].s2);
            if(cur1==-1||cur2==-1)continue;
            if(cur1==cur2)
            {
                for(int i=cur1;i<cur1+a[j].s1.size();i++)
                {
                    t1[i]=t2[i]='!';
                }
                if(t1==t2)ans++;
                t1=s1,t2=s2;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}


