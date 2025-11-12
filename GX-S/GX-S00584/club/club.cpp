#include<bits/stdc++.h>
using namespace std;
int T;
struct ren
{
    int num;
    int name;
    int tag;
}f[300030];
bool cmp(ren x,ren y)
{
    return x.num>y.num;
}
int vis[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int N;scanf("%d",&N);
        //cout<<"|"<<N<<endl;
        int s[4]={0};
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=N;i++)
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&f[(i-1)*3+j].num);
                //cout<<i<<" "<<j<<" "<<(i-1)*3+j<<" "<<f[(i-1)*3+j].num<<endl;
                f[(i-1)*3+j].tag=j;
                f[(i-1)*3+j].name=i;
            }
        sort(f+1,f+3*N+1,cmp);
        long long ans=0;
        int num=0;
        for(int i=1;i<=3*N;i++)
        {
            if(!vis[f[i].name]&&s[f[i].tag]<N/2)
            {
                ans+=f[i].num;
                vis[f[i].name]=1;
                s[f[i].tag]++;
            }
            //cout<<i<<" "<<" "<<f[i].num<<" "<<f[i].name<<" "<<f[i].tag<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
