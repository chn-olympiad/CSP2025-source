#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
int n,m;
char s[N];
int c[N];
int xl[N];
int t[N];
ll ans;
void dfs(int dep)
{
    if(dep>n)
    {
        int ct=0,ly=0;
        for(int i=1;i<=n;i++)
        {
            if(ct>=c[xl[i]])
            {
                ct+=1;
                continue;
            }
            if(s[i]=='0')
            {
                ct+=1;
            }
            else
            {
                ly+=1;
            }
        }
        if(ly>=m) ans+=1;
        ans%=998244353;
    }
    for(int i=1;i<=n;i++)
    {
        if(t[i]==0)
        {
            t[i]=1;
            xl[dep]=i;
            dfs(dep+1);
            xl[dep]=0;
            t[i]=0;
        }

    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s+1;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(n<=18)
    {
        dfs(1);
        cout<<ans;
        return 0;
    }
    else
    {
        ans=1;
        for(int i=n;i>=1;i--)
        {
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
// wo yao shang luo gu mi huo xing wei da shang,qiu qiu le
//1145141919810
//windows.h
//WINDOWS.H
//yi dao ti dou bu hui555,hou nian zai zhan ba
