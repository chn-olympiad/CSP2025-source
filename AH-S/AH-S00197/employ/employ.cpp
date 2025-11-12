#include<bits/stdc++.h>
using namespace std;
int n,m;string s;
int level[1000];
int patient[1000];
int vis[1000]={0};
vector<int> vec;long long sum=0;
bool checkkk(vector<int> j)
{
    int num=0;int uio=0;
    for(int i=0;i<j.size();i++)
    {
        if(level[i+1]==0)
        {
            uio++;
        }
        else
        {
            if(patient[vec[i]]>uio)
            {
                num++;
            }
            else uio++;
        }
    }
    if(num>=m)return true;
    return false;
}
void dfs(int id,int cnt)
{
    if(cnt==n)
    {
        if(checkkk(vec))
        {
            sum++;
            sum%=998244353;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;vec.push_back(i);
            dfs(i,cnt+1);
            vis[i]=0;vec.pop_back();
        }
    }
    return;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        level[i+1]=s[i]-'0';
    }
    for(int i=1;i<=n;i++)
    {
        cin>>patient[i];
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=1;vec.push_back(i);
        dfs(i,1);
        vis[i]=0;vec.pop_back();
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
