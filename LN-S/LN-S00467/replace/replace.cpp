#include<bits/stdc++.h>
using namespace std;
struct node
{
    int p,q,szc,szc2;
};
node ans[200009];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string c,c2;
        cin>>c>>c2;
        int pc,pc2;
        for(int j=0;j<c.size();j++)
        {
            if(c[j]=='b'){pc=j;break;}
        }
        for(int j=0;j<c2.size();j++)
        {
            if(c2[j]=='b'){pc2=j;break;}
        }
        ans[i].p=pc;
        ans[i].q=pc2;
        ans[i].szc=c.size();
        ans[i].szc2=c2.size();
    }
    while(q--)
    {
        int cnt=0,ps,pt;
        string s,t;
        cin>>s>>t;
        if(s==t){cnt++;}
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='b'){ps=i;break;}
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='b'){pt=i;break;}
        }
        int cz=ps-pt;
        //cout<<ps<<" "<<pt;
        for(int i=1;i<=n;i++)
        {
            //cout<<ans[i].p<<" "<<ans[i].q<<" "<<ans[i].szc<<" "<<ans[i].szc2<<endl;
            if(ans[i].p-ans[i].q==cz&&ans[i].szc<=s.size()&&ans[i].szc2<=t.size()&&ans[i].p<=ps&&ans[i].q<=pt){cnt++;}
        }
        cout<<cnt<<endl;
    }
    return 0;
}
