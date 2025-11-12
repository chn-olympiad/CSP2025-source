#include<bits/stdc++.h>
using namespace std;
int sum1=INT_MAX,a,b,c;
int e[11][100008];
struct jk{
        int a,b,c;
};
jk d[1000000];
bool t[100]={0};
void dfs(int sum,int i,bool p[])
{
    if(i>b+b*c)
        return;
     if(i>=0)
     {
         bool o=1;
         for(int i=0;i<b+c;i++)
         {
             if(p[i]==1)
             {
                 if(i<b)
                 {
                    t[d[i].a]=1;
                    t[d[i].b]=1;
                 }
                 else
                 {
                     if((i-b)%a!=0)
                        t[(i-b)%a]=1;
                 }
             }
         }
         for(int i=0;i<b;i++)
            if(t[i]==0)
         {
             o=0;
             break;
         }
         if(o==1)
             sum1=min(sum1,sum);
     }
         bool pi[b+c];
         for(int i=0;i<c;i++) pi[i]=p[i];
         pi[i]=1;
         if(i<b) dfs(sum+d[i].c,i+1,pi);
         if(i>=b) dfs(sum+e[(i-b)/b+1][i%b],i+1,pi);
         dfs(sum,i+1,p);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int sum=0;
    cin>>a>>b>>c;
    for(int i=0;i<b;i++)
    {
        cin>>d[i].a>>d[i].b>>d[i].c;
        sum+=d[i].c;
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<a+1;j++)
        {
            cin>>e[i][j];
            sum+=e[i][j];
        }
    }
    bool p[c+b]={0};
    dfs(0,0,p);
    cout<<d[0].c+d[1].c;
    return 0;
}
