#include<bits/stdc++.h>
#define LL long long

using namespace std;
const int N=505,M=998244353;
int n,m,c[N];
LL ans;
bool g[N],f[N];
LL p(int x)
{
LL sum=1;
    while(x>1)
    {
    sum=(sum*x)%M;
    x--;
    }
return sum;
}
LL q(int x,int y)
{
LL sum=1;
    while(x>y)
    {
    sum=(sum*x)%M;
    x--;
    }
return sum;
}
void solve1(int id,int sum,int cnt)
{
    if(cnt>=m)
    {
    ans=(ans+p(n-id+1))%M;
    return ;
    }
    if(id>n)
    {
    return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!f[i])
        {
        f[i]=1;
            if(g[id] && sum<c[i]) solve1(id+1,sum,cnt+1);
            else solve1(id+1,sum+1,cnt);
        f[i]=0;
        }
    }
    return ;
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    bool ff=1;
    int l=0;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
    g[i+1]=s[i]-'0';
        if(g[i+1]=='0') ff=0;
    }
    for(int i=1;i<=n;i++)
    {
    cin>>c[i];
        if(c[i]!=0) l++;
    }
    if(l<m)
    {
    cout<<0;
    return 0;
    }
    if(m==n)
    {
        if(ff && l==n) cout<<p(n);
        else cout<<0;
    return 0;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
        int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(c[j]>i-1) cnt++;
            }
            if(cnt==n-i+1)
            {
            ans=(ans+(((p(i-1)*cnt)%M)*(p(n-i)))%M)%M;
            break;
            }
        ans=(ans+(((p(i-1)*cnt)%M)*(p(n-i)))%M)%M;
        }
    cout<<ans;
    return 0;
    }
    if(ff)
    {
    cout<<q(l,m);
    return 0;
    }
    if(n<=18)
    {
    solve1(1,0,0);
    cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
