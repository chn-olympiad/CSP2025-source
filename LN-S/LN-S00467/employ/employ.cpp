#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[509];
int ans=0;
vector<int> an;
int n,h;
string s;
bool vis[509];
void dfs(int cnt)
{
    if(cnt==n)
    {
        int sum=0;
        for(int i=0;i<an.size();i++)
        {
            if(s[i]=='1'&&an[i]>=i){sum++;}
        }
        if(sum>=h){ans++;}
        an.clear();
        ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            cnt++;
            an.push_back(a[i]);
            dfs(cnt);
            cnt--;
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>h;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){cin>>a[i];}
    dfs(0);
    cout<<ans;
    return 0;
}
