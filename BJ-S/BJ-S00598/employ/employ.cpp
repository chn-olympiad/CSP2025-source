#include<bits/stdc++.h>
using namespace std;
int data[100000];
bool vis[1000000];
int re[1000000];
long long int n,m,res;
long long int mmm;
string bad;
bool check()
{
    long long int fail=0,ress=0;
    for(int i=0;i<n;i++)
    {
        if(bad[i]=='0'||re[i]<=fail){
            fail++;
        }
        else{
            ress++;
        }
    }
    if(ress>=m)
        return 1;
    else
        return 0;
}
int dfs(int level=1){
    if(level==n)
    {
        if(check())
            res=(res+1)%998244353;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            re[level]=data[i];
            dfs(level+1);
            vis[i]=0;
        }
    }
}
int main()
{

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>bad;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    for(int i=1;i<=n;i++){
        vis[i]=1;
        re[0]=data[i];
        dfs();
        vis[i]=0;
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
