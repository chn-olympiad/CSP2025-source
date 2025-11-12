#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
}x[100005];
int n,m,T,maxn;
void dfs(int t,int s1,int s2,int s3,int sum1,int sum2,int sum3)
{
    if(t==n+1)
    {
        int sum=sum1+sum2+sum3;
        if(maxn<sum)
            maxn=sum;
        return ;
    }
    // cout<<sum1+sum2+sum3<<endl;
    int t2=t+1;
    if(s1<m)
        dfs(t2,s1+1,s2,s3,sum1+x[t].a,sum2,sum3);
    if(s2<m)
        dfs(t2,s1,s2+1,s3,sum1,sum2+x[t].b,sum3);
    if(s3<m)
        dfs(t2,s1,s2,s3+1,sum1,sum2,sum3+x[t].c);
}
void dfs2(int t,int s1,int s2,int sum1,int sum2)
{
    if(t==n+1)
    {
        int sum=sum1+sum2;
        if(maxn<sum)
            maxn=sum;
        return ;
    }
    // cout<<sum1+sum2+sum3<<endl;
    int t2=t+1;
    if(s1<m)
        dfs2(t2,s1+1,s2,sum1+x[t].a,sum2);
    if(s2<m)
        dfs2(t2,s1,s2+1,sum1,sum2+x[t].b);
}
bool cmp1(node x,node y)
{
    return x.a>y.a;
}
void club()
{
	cin>>n;
    m=n/2,maxn=0;
    for(int i=1;i<=n;i++)
        cin>>x[i].a>>x[i].b>>x[i].c;
    if(n<=10)
    {
        dfs(1,0,0,0,0,0,0);
        cout<<maxn<<endl;
    }
    else if(x[1].b==0 && x[1].c==0)
    {
        sort(x+1,x+1+n,cmp1);
        for(int i=1;i<=n/2;i++)
            maxn+=x[i].a;
        cout<<maxn<<endl;
    }
    else
    {
        dfs2(1,0,0,0,0);
        cout<<maxn<<endl;
    }
}
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
    {
		club();
    }
	return 0;
}
