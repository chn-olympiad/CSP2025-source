#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int pos=0;
int a[N],s[N][N];
int pairs[N*N][2];
int counts[N*N][2];
int sum[N*N][2];
int ans1,ans2;
void dfs1(int x,int ans)
{
    sum[x][1]=max(sum[x][1],ans);
    //cout<<sum[x][1]<<endl;
    bool pd=0;
    for(int i=1;i<x;i++)
    {
        if(pairs[i][1]!=0)
        {
            pd=1;
        }
    }
    if(!pd)
    {

        return ;
    }
    else
    {
        for(int i=1;i<x;i++)
        {
            if(pairs[i][2]<pairs[x][1])
            {
                counts[x][1]++;
                //cout<<counts[x][1]<<endl;
                //cout<<pairs[i][1]<<" "<<pairs[i][2]<<endl;
                //cout<<pairs[x][1]<<" "<<pairs[x][2]<<endl;
                //cout<<"dfs1------------------------------------"<<endl;
                dfs1(i,counts[x][1]);
                counts[x][1]--;
            }
        }
    }
}
void dfs2(int x,int ans)
{
    sum[x][2]=max(sum[x][2],ans);
    //cout<<sum[x][2]<<endl;
    //cout<<counts[x][2]<<endl;
    bool pd=0;
    for(int i=x+1;i<=pos;i++)
    {
        if(pairs[i][1]!=0)
        {
            pd=1;
        }
    }
    if(!pd)
    {
        return ;
    }
    else
    {
        for(int i=x+1;i<=pos;i++)
        {
            if(pairs[i][1]>pairs[x][2])
            {
                counts[x][2]++;
                //cout<<counts[x][2]<<endl;
                //cout<<pairs[i][1]<<" "<<pairs[i][2]<<endl;
               // cout<<pairs[x][1]<<" "<<pairs[x][2]<<endl;
                //cout<<"dfs2------------------------------------"<<endl;
                dfs2(i,counts[x][2]);
                counts[x][2]--;
            }
        }
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        s[1][i]=s[1][i]^a[i];
    }
    for(int i=2;i<=n;i++)
    {
        s[i][i]=a[i];
        for(int j=i;j<=n;j++)
        {
            s[i][j]=s[i-1][j]^a[i];
        }
    }

    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=n;j++)
        {
            if(s[i][j]==k)
            {
                pos++;
                pairs[pos][1]=i;
                pairs[pos][2]=j;
            }
        }
    }
    dfs1(pos,0);
    dfs2(1,0);
    int maxn=INT_MIN;
    for(int i=1;i<=pos;i++)
    {
        maxn=max(maxn,sum[i][1]+sum[i][2]+1);
    }
    cout<<maxn;
    return 0;
}
