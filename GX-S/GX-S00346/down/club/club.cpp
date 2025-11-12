#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[N][4];
int f[N][4];
int ans;
void dfs(int t,int num,int c1,int c2,int c3)
{
	if(t>n)
	    return num;
	if(c1<n/2&&f[t][1]==0)
	    return f[t][1]=dfs(t+1,num+a[t][1],c1+1,c2,c3);
	 else
	     return f[t][1];
	if(c2<n/2&&f[t][2]==0)
	    return f[t][2]=dfs(t+1,num+a[t][2],c1,c2+1,c3);
	else
	     return f[t][2];
	if(c3<n/2&&f[t][3]==0)
	    return f[t][3]=dfs(t+1,num+a[t][3],c1,c2,c3+1);
	else
	     return f[t][3];
}
void init()
{
	mement(a,0,sizeof());
int main()
{
    freopen("club.ans","r",stdin);
    freopen("club.in","it",stdout);
    int n;
    cin>>t;
    while(t--)
    {
        init();ans=0;
        cin>>n
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int k=dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
