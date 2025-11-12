#include<iostream>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1e5;
int a[MAXN+5][4];
int ans=INT_MIN;
int n;
void dfs(int x,int sum,int cnt1,int cnt2,int cnt3)
{
    if(cnt1>n/2||cnt2>n/2||cnt3>n/2)
    {
        return;
    }
    if(x>n)
    {
        ans=max(ans,sum);
        return;
    }
    dfs(x+1,sum+a[x][1],cnt1+1,cnt2,cnt3);
    dfs(x+1,sum+a[x][2],cnt1,cnt2+1,cnt3);
    dfs(x+1,sum+a[x][3],cnt1,cnt2,cnt3+1);
    return;
}
void dfs1(int x,int sum,int cnt1,int cnt2)
{
    if(cnt1>n/2||cnt2>n/2)
    {
        return;
    }
    if(x>n)
    {
        ans=max(ans,sum);
        return;
    }
    dfs1(x+1,sum+a[x][1],cnt1+1,cnt2);
    dfs1(x+1,sum+a[x][2],cnt1,cnt2+1);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ans=INT_MIN;
        cin>>n;
        bool flaga=true,flagb=true;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0)
            {
                flaga=false;
            }
            if(a[i][3]!=0)
            {
                flagb=false;
            }
        }
        if(flaga)
        {
            priority_queue<int>q;
            for(int i=1;i<=n;++i)
            {
                q.push(a[i][1]);
            }
            ans=0;
            for(int i=1;i<=n/2;++i)
            {
                ans+=q.top();
                q.pop();
            }
            cout<<ans<<'\n';
            continue;
        }
        else if(flagb)
        {
            dfs1(1,0,0,0);
            cout<<ans<<'\n';
            continue;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}
