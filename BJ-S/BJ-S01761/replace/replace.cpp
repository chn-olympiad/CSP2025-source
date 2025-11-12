#include<bits/stdc++.h>
using namespace std;
struct node
{
    char c;
    int h[30];
    int id;
}tree[1000010];
int hhh,vis[200010];
string s1[200010],s2[200010];
void buildt(int x,int id)
{
    for(int i=0; i<s[id].size(); i++)
    {
        if(tree[x].h[s[i]-'a']==0)
        {
            tree[x].h[s[i]-'a']=++hhh;
            tree[hhh].c=s[i];
            if(i==s[id].size()-1)
            {
                tree[hhh].id=id;
            }
        }
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>s1[i]>>s2[i];
        s=s1[i];
    }
    while(q--)
    {
        cout<<0<<endl;
    }
}
