#include <bits/stdc++.h>
using namespace std;
int const mod=998244353;
int n,m,lev[505],fail,c;
string s;
int cnt[505],mul,ans;
void dfs(int f,int g,int h){
    if(g==n+1)
    {
        ans=(ans*1LL+h)%mod;
        return;
    }
    if(lev[g]==0)
    {
        dfs(f+1,g+1,h);
        return;
    }
    int i=0,j,k;
    if(f+m==n)
    {
        i=f+1;
    }
    for(i;i<=500;i++)
    {
        if(cnt[i])
        {
            j=f;
            k=(h*1LL*cnt[i])%mod;
            if(f>=i)
            {
                j++;
            }
            if(j+m>n)
            {
                continue;
            }
            cnt[i]--;
            dfs(j,g+1,k);
            cnt[i]++;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    cin>>s;
    for(int i=0;i<n;i++)
    {
        lev[i+1]=s[i]-'0';
        if(s[i]=='0')
        {
            fail++;
        }
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c);
        cnt[c]++;
    }
    dfs(0,1,1);
    mul=1;
    for(int i=2;i<=fail;i++)
    {
        mul=(mul*1LL*i)%mod;
    }
    ans=(ans*1LL*mul)%mod;
    printf("%d",ans);
    return 0;
}
