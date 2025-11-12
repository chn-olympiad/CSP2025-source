#include<bits/stdc++.h>
using namespace std;
int t,n;
long long a[3][100005],ans,now;
void dfs(int wei,int yi,int er,int san)
{
	if(yi>n/2||er>n/2||san>n/2)
	{
		return ;
	}
	if(wei>n)
	{
		ans=max(ans,now);
		return;
	}
	for(int i=0;i<=2;i++)
	{
		if(i==0)
		{
			now+=a[i][wei];
			dfs(wei+1,yi+1,er,san);
			now-=a[i][wei];
		}
		else if(i==1)
		{
			now+=a[i][wei];
			dfs(wei+1,yi,er+1,san);
			now-=a[i][wei];
		}
		else if(i==2)
		{
			now+=a[i][wei];
			dfs(wei+1,yi,er,san+1);
			now-=a[i][wei];
		}
	}
}
bool dadx(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool pan12=true;
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			ans1+=max(a[0][i],max(a[1][i],a[2][i]));
			if(a[1][i]!=0||a[2][i]!=0)
			{
				pan12=false;
			}
		}
		if(n<=10)
		{
			dfs(1,0,0,0);
			cout<<ans<<'\n';
			ans=0;
			now=0;
		}
		else if(pan12)
		{
			sort(a[0]+1,a[0]+1+n,dadx);
			ans1=0;
			for(int i=1;i<=n/2;i++)
			{
				ans1+=a[0][i];
			}
			cout<<ans1<<'\n';
			ans=0;
			now=0;
			ans1=0;
		}
		else 
		{
			cout<<ans1<<'\n';
			ans1=0;
			ans=0;
			now=0;
		}
	}
	//Ren5Jie4Di4Ling5%
	//cout<<'\n'<<"freopen!!!!!!!!!!";
	return 0;
}
