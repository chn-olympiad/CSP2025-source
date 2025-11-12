#include<iostream>
#include<algorithm>
using namespace std;
int maxn;int n;
int cnt[4];
int a[100010][5];
void dfs(int dep,int sum)
{
    if(dep>n)
    {
        maxn=max(maxn,sum);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(cnt[i]<n/2)
        {
            cnt[i]++;
            dfs(dep+1,sum+a[dep][i]);
            cnt[i]--;
        }
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        maxn=-1;
        dfs(1,0);
        cout<<maxn<<endl;
    }
    return 0;
}
