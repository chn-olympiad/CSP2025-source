#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],v[505],cnt;
string s;
void dfs(long long step,long long r)
{
    if(step==n-1)
    {
        if(n-r>=m)cnt++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            if(s[step]=='0' || r>=c[i])dfs(step+1,r+1);
            else dfs(step+1,r);
            v[i]=0;
        }
    }
    return ;
}
int main(void){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&c[i]);
    }
    dfs(0,0);
    printf("%lld",cnt);
    return 0;
}
