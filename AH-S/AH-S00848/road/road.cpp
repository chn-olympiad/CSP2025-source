#include<bits/stdc++.h>
using namespace std;
struct lb
{
    int zd,w;
}dui[1000005];
int len;
int mapp[10001][10001],arr[10005],ans;
bool tt[10005];
void dg(int mb,int n)
{
    tt[mb]=1;
    for(int i=1;i<=n;i++)
    {
        if(mapp[mb][i]!=1000000005)
        {
            //cout<<mb<<" "<<i<<"    ";
            len++;
            dui[len]={i,mapp[mb][i]};
        }
    }
    int min_id=0;
    for(int i=1;i<=len;i++)
    {
        if(tt[i]==1)continue;
        if(dui[i].w<dui[min_id].w)min_id=i;
    }
    //cout<<dui[min_id].w<<" "<<dui[min_id].zd<<" "<<min_id<<" "<<len<<"     ";
    if(min_id==0)return;
    ans+=dui[min_id].w;
    dg(dui[min_id].zd,n);
}
int main()
{
    freopen("road1.in","r",stdin);
    //freopen("road.out","w",stdout);
    dui[0]={0,0x7fffffff};
    int n,m,k;
    cin>>n>>m>>k;
    for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
            mapp[j][k]=1000000005;
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        mapp[a][b]=w;
        mapp[b][a]=w;
    }
    for(int i=1;i<=k;i++)
    {
        int w;
        cin>>w;
        for(int j=1;j<=n;j++)
            cin>>arr[j];
        for(int j=1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
               if(arr[j]+arr[k]+w<mapp[j][k])
                {
                    mapp[j][k]=arr[j]+arr[k]+w;
                    mapp[k][j]=arr[j]+arr[k]+w;
                }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<mapp[i][j]<<" ";
        }
        cout<<endl;
    }
    dg(1,n);
    cout<<ans;
    return 0;
}
