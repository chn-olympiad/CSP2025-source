#include<bits/stdc++.h>
using namespace std;
int b[100005][3],sum1=0;
void dfs(int a,int sum,int d[3],int p)
{
    int pi[3];
    pi[0]=d[0],pi[1]=d[1],pi[2]=d[2];
    if(a==p)
        sum1=max(sum1,sum);
    if(d[0]<p/2)
    {
        pi[0]++;
        dfs(a+1,sum+b[a][0],pi,p);
        pi[0]--;
    }
    if(d[1]<p/2)
    {
        pi[1]++;
        dfs(a+1,sum+b[a][1],pi,p);
        pi[1]--;
    }
    if(d[2]<p/2)
    {
        pi[2]++;
        dfs(a+1,sum+b[a][2],pi,p);
        pi[2]--;
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,sum=0;
        cin>>a;
        struct jk{
            int a,b[3]={0};
        };
        sum1=0;
        int d[3]={0};
        for(int ii=0;ii<a;ii++) cin>>b[ii][0]>>b[ii][1]>>b[ii][2];
        dfs(0,0,d,a);
        cout<<sum1<<endl;
    }
    return 0;
}
