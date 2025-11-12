#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int kx[1000000][3],kxi=0;
int xx[500000][25];
int c[25]={0};
int waswas(int m,int p)
{
    for(int i=1;i<=kxi;i++)
        if(kx[i][1]>m)
            return max(waswas(kx[i][2],p+1),p+1);
    return p;
}
int awyh(int a,int b)
{
    for(int i=0;i<=24;i++)
        c[i]=0;
    for(int i=a;i<=b;i++)
        for(int j=1;j<=xx[i][0];j++)
        {
            c[j]+=xx[i][j];
            c[j]=c[j]%2;
        }
    for(int i=1;i<=24;i++)
        if(c[i]!=xx[0][i])
            return 0;
    kxi++;
    kx[kxi][1]=a;
    kx[kxi][2]=b;
    return 0;
}
int dfs(int m,int a)
{
    int ai=0;
    while(a>0)
    {
        ai++;
        xx[m][ai]=a%2;
        a/=2;
    }
    xx[m][0]=ai;
    return 0;
    /*for(int i=0;i<=ai;i++)
        cout<<xx[m][i]<<" ";
    cout<<endl;*/
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    dfs(0,k);
    for(int i=1;i<=n;i++)
    {
        cin>>q;
        dfs(i,q);
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            awyh(i,j);
    /*for(int i=1;i<=xx[0][0];i++)
        cout<<xx[0][i]<<" ";
    cout<<endl<<kxi<<endl;
    for(int i=1;i<=kxi;i++)
        cout<<kx[i][1]<<" "<<kx[i][2]<<endl;*/
    cout<<waswas(0,0);
    return 0;
}
