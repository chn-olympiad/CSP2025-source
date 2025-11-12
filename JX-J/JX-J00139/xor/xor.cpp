#include<bits/stdc++.h>
using namespace std;

int cnt[500010][21],a[500010],n,k,k_b[21],cur[21],ans;
void get_binary(int x,int p)
{
    for(int i=0;x;i++)
    {
        cnt[p][i]+=(x&1);
        x>>=1;
    }
    //for(int i=20;i>=0;i--)
     //   cout<<cnt[p][i];
    //cout<<'\n';
}
void get_sum(int l,int r)
{
    for(int i=0;i<=20;i++)
        cur[i]=cnt[r][i]^cnt[l-1][i];
    //for(int i=20;i>=0;i--)
       // cout<<cur[i];
    //cout<<"\n";
}
bool check()
{
    for(int i=0;i<=20;i++)
    {
        if(cur[i]!=k_b[i])
            return 0;
    }
    return 1;
}
void input()
{
    cin>>n>>k;
    for(int i=0;k;i++)
    {
        k_b[i]+=(k&1);
        k>>=1;
    }
    //for(int i=20;i>=0;i--)
     //   cout<<k_b[i];
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        get_binary(tmp,i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=20;j++)
        {
            cnt[i][j]^=cnt[i-1][j];
        }
    }

}

void solution()
{
    int l=1,r=1;
    while(l<=n)
    {
        get_sum(l,r);
        if(check())
        {
            ans++;
            cout<<l<<' '<<r<<'\n';
            l=r+1;
        }
        if(r<n)
            r++;
        else
            l++;
    }
    cout<<ans;
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    solution();
    return 0;
}
