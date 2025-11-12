#include<bits/stdc++.h>
using namespace std;
int T,n,ans,x,y,z;
int a[100005][5];

void dfs(int cur,int sum)
{
	if(2*x>n||2*y>n||2*z>n)return;
	if(cur == n + 1)
	{
		ans = max(ans,sum);
//		cout<<sum<<endl;
//		cout<<endl<<"~~~~~~~"<<endl;
		return ;
	}
	
	
	
//	cout<<a[cur][1]<<' ';
	x++;
	dfs(cur+1,sum+a[cur][1]);
	x--;
//	cout<<a[cur][2]<<' ';
	y++;
	dfs(cur+1,sum+a[cur][2]);
	y--;
//	cout<<a[cur][3]<<' ';
	z++;
	dfs(cur+1,sum+a[cur][3]);
	z--;

}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans = -1,x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
//			cout<<a[i][1]<<a[i][2]<<a[i][3];
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
