
#include<bits/stdc++.h>
using namespace std;
struct node{
    string first;
    string second;
};
int n,q,go_out,mark;
string tmp;
node a[200005],change[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>change[i].first>>change[i].second;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>a[i].first>>a[i].second;
    }

    for(int kk=1;kk<=q;kk++)
    {
        mark=0;
        for(int i=0;i<a[kk].first.size();i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[kk].first[i]==change[j].first[0])
                {
                    tmp=a[kk].first;
                    tmp[i]=change[j].second[0];
                    go_out=0;
                    if(i+change[j].first.size()>a[kk].first.size()) continue;
                    for(int x=1;x<change[j].first.size();x++)
                    {
                        if(tmp[i+x]!=change[j].first[x])
                        {
                            go_out=1;
                        }
                        else
                        {
                            tmp[i+x]=change[j].second[x];
                        }
                    }
                    if(go_out) continue;
                    if(tmp==a[kk].second) mark++;
                }
            }
        }
        cout<<mark<<endl;
    }
    return 0;
}
