#include<bits/stdc++.h>
using namespace std;
int a[110000][3],n,maxn=0;
int dfs(int i,int x,int y,int z,int sum)
{
	if(i==n+1)return maxn=max(maxn,sum),0;
	if(x<n/2)dfs(i+1,x+1,y,z,sum+a[i][0]);
	if(y<n/2)dfs(i+1,x,y+1,z,sum+a[i][1]);
	if(z<n/2)dfs(i+1,x,y,z+1,sum+a[i][2]);
	return 0;
}
void solve()
{
	cin>>n;
	maxn=0;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][1]!=0 or a[i][2]!=0)f=0;
	}
	if(f==1)
	{
		vector<int>vv;
		for(int i=1;i<=n;i++)vv.push_back(a[i][0]);
		sort(vv.begin(),vv.end(),greater<int>());
		int ans=0;
		for(int i=0;i<n/2;i++)ans+=vv[i];
		cout<<ans<<endl;
		return ;
	}
	dfs(1,0,0,0,0);
	cout<<maxn<<endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

//0 2 2
//2 2 0
//2 0 2
//
//
//
//3 0 3  
//0 0 2
//0 3 3  
//1 1 1
//
//3 0 3
//1 1 1
//0 3 3
//0 0 2
//
//0 3 3
//1 1 1
//3 0 3
//0 0 2
//
//3 0 10
//0 3 9
//0 0 2
//1 1 1
//
//1     2     3  
//
//1(3)  3(3)  1(10)
//4(1)  4(1)  3(9)
//3(0)  1(0)  2(2)
//2(0)  2(0)  4(1)
//
//1£º4 2
//2£º
//3£º1 3
