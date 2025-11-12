#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
string s[200005];
int tr[19000000][26],cnt;
int p[19000000];
int vis[19000000];
int tttp,ttt2;
void inst(const string &x,const int &id)
{
    tttp=0;
    for(int i=0;i<x.size();i++)
    {
        if(tr[tttp][x[i]-'a']==0)
        {
            cnt++;
            tr[tttp][x[i]-'a']=cnt;
        }
        tttp=tr[tttp][x[i]-'a'];
    }
    vis[tttp]=id;
}
void sp(int x)
{
    for(int i=0;i<26;i++)
    {
        if(tr[x][i])
        {
            ttt2=p[x];
            while(tr[ttt2][i]==0&&ttt2!=0)
                ttt2=p[ttt2];
                // cout<<tr[x][i]<<" "<<tr[ttt2][i]<<"\n";
            if(tr[x][i]!=tr[ttt2][i])
                p[tr[x][i]]=tr[ttt2][i];
            sp(tr[x][i]);
        }

    }
}
bool check(const string&y,const string &x,const int &id,const int &pos)
{
    for(int i=0;i<s[id].length();i++)
    {
        if(i>pos||x[pos-s[id].length()+i+1]!=s[id][i]) return false;
    }
    for(int i=0;i<x.length();i++)
    {
        if((i<pos-s[id].length()+1||i>pos)&&x[i]!=y[i]) return false;
    }
    return true;
}
int count_(const string &x,const string &y)
{
    tttp=0,ttt2=0;
    for(int i=0;i<x.size();i++)
    {
        while(tr[tttp][x[i]-'a']==0&&tttp!=0)
            tttp=p[tttp];
         tttp=tr[tttp][x[i]-'a'];
        int tmp=tttp;
        while(tmp!=0)
        {
            if(vis[tmp]!=0&&check(x,y,vis[tmp],i))
                ttt2++;
            tmp=p[tmp];
        }
    }
    return ttt2;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    string s_;
    for(int i=1;i<=n;i++)
    {
        cin>>s_>>s[i];
        inst(s_,i);
    }
    sp(0);
    // for(int i=0;i<=cnt;i++)
    // {
    //     for(int j=0;j<26;j++)
    //     {
    //         if(tr[i][j]) cout<<i<<" "<<tr[i][j]<<" "<<j<<"\n";
    //     }
    //     cout<<i<<" "<<p[i]<<"\n";
    // }
    string q,q1;
    for(int i=1;i<=m;i++)
    {
        cin>>q>>q1;
        if(q.size()!=q1.size())
        {
            cout<<0<<"\n";
            continue;
        }
        cout<<count_(q,q1)<<"\n";
    }
    return 0;
}
