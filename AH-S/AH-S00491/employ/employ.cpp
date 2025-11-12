#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int c[N],p[N];
char b[N];int n,m;long long ans=0;
bool ch[N];long long sum=0;
void dfs(int step,int tot,int sum)
{
    if(step==n)
    {
        if(sum>m)ans++;

        ans=ans%998244353;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!ch[i]&&tot<c[i])
        {
            if(p[i]==0)tot++;
            else
            {
                sum++;
                ch[i]=1;
                dfs(step+1,tot,sum);
                ch[i]=0;
            }

        }

    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<=s.size()-1;i++)
    {
        p[i+1]=s[i]-'0';
    }

    for(int i=1;i<=n;i++)
    {
        if(!ch[i]&&0<c[i])
        {
            sum++;
            ch[i]=1;
            dfs(1,0,sum);
            ch[i]=0;

        }

    }
    cout<<ans;
    return 0;
}
