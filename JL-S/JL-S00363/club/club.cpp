#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;

int t,n;
int flag;
int a[N][5];
long long ans;
long long f;
int p[N][5];
int cnt[5];
int tem;
int s[N];
long long aws=0;

void dfs(int l)
{
    if(l==n+1)
    {
            ans=max(ans,f);
    }

    else
    {
    for(int i=1;i<=3;i++)
    {
        if(p[l][i]==0&&cnt[i]<n/2)
        {
            f+=a[l][i];
            p[l][i]=1;
            cnt[i]++;
            dfs(l+1);
            f-=a[l][i];
            p[l][i]=0;
            cnt[i]--;
        }
    }
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
    ans=0;aws=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(a[i][2]!=0||a[i][3]!=0) flag=1;
    }
    if(flag==1)
    {
        dfs(1);
        cout<<ans<<endl;
    }
    if(flag==0)
    {
        for(int i=1;i<=n;i++) s[i]=a[i][1];
        sort(s,s+n+1);
        for(int j=n;j>(n/2);j--) aws+=s[j];
        cout<<aws<<endl;
    }
    }
    return 0;
}

