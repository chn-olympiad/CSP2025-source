#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,q;
struct node
{
    string first,second;
};
node s[200008],t[200008];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].first>>s[i].second;
    }
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        cin>>t[i].first>>t[i].second;
        for(int j=1;j<=n;j++)
        {
            string cur=t[i].first;
            if(s[j].first.size()>t[i].first.size()) continue;
            for(int k=0;k<t[i].first.size()-s[j].first.size()+1;k++)
            {
                cur=t[i].first;
                bool ok=true;
                for(int l=0;l<s[j].first.size();l++)
                {
                    if(s[j].first[l]!=t[i].first[k+l])
                    {
                        ok=false;
                        break;
                    }
                    cur[k+l]=s[j].second[l];
                }
                if(ok)
                {
                    if(cur==t[i].second)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
