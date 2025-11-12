#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q,ans;
string s1[N],s2[N];
bool v[N];
/*
void Bfs(string x,string answer)
{
    queue<string> q;
    q.push(x);
    while(!q.empty())
    {
        string ox=q.front();
        q.pop();
        if(ox==answer)
            ans++;
        for(int i=1;i<=n;i++)
        {
            int f=ox.find(s1[i]);
            if(f!=-1)
            {
                string nx=ox;
                nx.erase(f,s1[i].size());
                nx.insert(f,s2[i]);
                q.push(nx);
            }
        }
    }
}
void dfs(string x,string answer)
{
    if(x==answer)
    {
        ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        int f=x.find(s1[i]);
        if(f!=-1&&v[i]!=1)
        {
            string nx=x;
            nx.erase(f,s1[i].size());
            nx.insert(f,s2[i]);
            v[i]=1;
            dfs(nx,answer);
            v[i]=0;
        }
    }
}*/
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++)
    {
        ans=0;
        string t1,t2;
        cin>>t1>>t2;
        for(int i=1;i<=n;i++)
        {
            int f=t1.find(s1[i]);
            if(f!=-1)
            {
                string nx=t1;
                nx.erase(f,s1[i].size());
                nx.insert(f,s2[i]);
                if(nx==t2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
}
