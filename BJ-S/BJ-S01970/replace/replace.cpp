#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,s1;
struct node
{
    string x,y;
}a[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    while(q--)
    {
        cin>>s>>s1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int l=-1,pos=s.find(a[i].x);
            while(pos!=-1)
            {
                string s2=s.substr(0,pos)+a[i].y+s.substr(pos+a[i].x.size());
                if(s1==s2)
                {
                    ans++;
                }
                l=pos+1;
                pos=s.find(a[i].x,l);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
