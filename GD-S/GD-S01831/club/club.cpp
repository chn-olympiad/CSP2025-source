#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans,mem[4];
struct node
{
	int x,y,z;
}a[N];
bool pd;
void dfs(int t,int sum)
{
	if(t==n+1)
	{
		ans=max(ans,sum);
	}
	if(mem[1]<n/2)
	{
		mem[1]++;
		dfs(t+1,sum+a[t].x);
		mem[1]--;
	}
	if(mem[2]<n/2)
	{
		mem[2]++;
		dfs(t+1,sum+a[t].y);
		mem[2]--;
	}
	if(mem[3]<n/2)
	{
		mem[3]++;
		dfs(t+1,sum+a[t].z);
		mem[3]--;
	}
}
bool cmp(node x,node y)
{
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0,pd=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y||a[i].z)pd=1;
		}
		sort(a+1,a+1+n,cmp);
		if(pd==1)dfs(1,0);
		else
		{
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].x;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//freopen("club.in","r",stdin);
//freopen("club.out","w",stdout);
/*爆0咯,看了这么多退役的，终于到我了*/ 
