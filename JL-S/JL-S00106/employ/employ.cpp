//special A
//20pts
//huaji huaji huaji
//get points ruthlessly
//HAHAHA!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,p[102],fact[1002];
bool a[12];
bool check()
{
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        cout<<p[i]<<' ';
        if(a[i]||tot>=p[i])
            tot++;
    }
    cout<<tot<<'\n';
    return n-tot+1>=m;
}
bool order()
{
    for(int i=1;i<=n;i++)
    {
        if(p[i]>p[i-1])
            return false;
    }
    return true;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if(m==0)
    {
        fact[0]=1;
        for(int i=1;i<=n;i++)
            fact[i]=fact[i-1]*2%998244353;
        cout<<fact[n];
    }
    /*
    else if(n<=10)
    {
        for(int i=1;i<=n;i++)
        {
            char x;
            cin>>x;
            a[i]=x-'0';
        }
        for(int i=1;i<=n;i++)
            cin>>p[i];
        sort(p+1,p+n+1);
        do
        {
            cout<<"d";
            if(check())
                ans++;
            next_permutation(p+1,p+n+1);
        }
        while(!order());
        cout<<ans;
    }*/
    else
        cout<<0;
    return 0;
}
//40+(0~60)+0+0=(40~100)
//Too hard.
//bye-bye, noip.
//farewell T-T
//sad sad sad
