#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
    int id,id2;
    int va;
};
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    string a,b;
    vector<node> v;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        int cur1,cur2;
        for(int i=0;i<=a.size();i++)
        {
            if(a[i]=='b') cur1=i;
        }
        for(int i=0;i<=b.size();i++)
        {
            if(b[i]=='b') cur2=i;
        }
        int c=cur2-cur1;
        v[i].va=c;
        v[i].id=cur1;
        v[i].id2=b.size()-cur2-1;
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        int cur1,cur2;
        for(int i=0;i<=t1.size();i++)
        {
            if(t1[i]=='b') cur1=i;
        }
        for(int i=0;i<=t2.size();i++)
        {
            if(t2[i]=='b') cur2=i;
        }
        int c=cur2-cur1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int cnt=c/v[i].va;
            if(cnt*v[i].va==c)
            {
                if(cur1>=v[i].id && t2.size()-cur2-1>=v[i].id2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
