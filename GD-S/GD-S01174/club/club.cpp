#include<bits/stdc++.h> 
using namespace std;
struct node{
	int a,b,c;
} f[114514];
int n;
int ans;
void dfs(int no,int a,int b,int c,int sum)
{
	if(no>n)
	{
		ans=max(ans,sum);
		return ;
	}
	int i,j,k;
	if(a<n/2) dfs(no+1,a+1,b,c,sum+f[no].a);
	if(b<n/2) dfs(no+1,a,b+1,c,sum+f[no].b);
	if(c<n/2) dfs(no+1,a,b,c+1,sum+f[no].c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,m;
		cin>>n;
		ans=0;
		for(i=1;i<=n;i++)
		{
			cin>>f[i].a>>f[i].b>>f[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
