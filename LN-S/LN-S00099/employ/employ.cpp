#include<bits/stdc++.h>
#define itn int
using namespace std;
int c[505];
string s;
int st[505];
bool vis[505];
int n,m;
int cnt=0;
void dfs(int step,int ans,int k)
{
    if(step>=n)
    {
        if(ans>=m)
        {
            cnt++;
            //cout<<1;
            cnt=cnt%998244353;
        }
        return;
    }
    for(itn i=1;i<=n;i++)
    {
        if(vis[i]){
            continue;
        }
        vis[i]=1;
        if(st[step+1]==1)
            dfs(step+1,ans+(k<c[i]),k);
        else
            dfs(step+1,ans,k+1);
        vis[i]=0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        st[i]=s[i-1]-'0';
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    /*do
    {
        //cout<<"1";
        int k=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(k>=c[i])
            {
                //cout<<2;
            }
            else if(st[i]==0)
            {
                //cout<<3;
                k++;
                continue;
            }
            else
            {
                ans++;
                //cout<<4;
            }

        }
        if(ans>=m){
            cnt=(cnt+1)%998244353;
            //cout<<5;
            //cout<<cnt;
        }
    }while(next_permutation(c+1,c+n+1));*/
    dfs(0,0,0);
    cout<<cnt<<endl;
    return 0;
}
