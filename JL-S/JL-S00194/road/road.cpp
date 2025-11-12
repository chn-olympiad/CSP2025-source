#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005];
long long ans;
//int a[15][10005],c[15],num[10005],t[1000015][5];
//vector int e[10005];
//bool z(int l)
//{
    //int s[n+5];
    //memset(s,0,sizeof(s));
    //for(int i=0;i<num[1];i++)}
    //{
        //s[e[num[1]][i]]++;
    //}
    //for(int i=l;i<=n;i++)
    //{
        //if(!s[i])
        //{
            //return 0;
        //}
    //}
    //return 1;
//}
//void p(int x,int y)
//{
    //e[x].push_back(y);
    //num[x]++;
    //e[x].push_back(y);
    //num[y]++;
    //for(int j=0;j<num[y];j++)
    //{
        //e[x].push_back(e[y][j]);
    //}
    //num[x]+=num[y];
    //for(int j=0;j<num[x];j++)
    //{
        //e[y].push_back(e[x][j]);
    //}
        //num[y]+=num[x];
//}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        //t[i][1]=u[i];
        //t[i][2]=v[i];
        ans+=w[i];
    }
    //for(int i=1;i<=k;i++)
    //{
        //cin>>c[i];
        //for(int j=1;j<=n;j++)}
        //{
            //cin>>a[i][j];
        //}
    //}
    cout<<ans;
    return 0;
}
