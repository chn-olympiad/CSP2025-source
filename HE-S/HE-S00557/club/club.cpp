#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
const long long mod=1e9+7;
int t;
//记得检查盘，存盘，freopen，删注释，删文件 
int n,a[N][4];
long long ans;
void gma(long long &x,long long y)
{
	x<y?x=y:0;
}
void dfs(int x,long long sum,int c1,int c2,int c3)
{
	if(x==n+1)
	{
		gma(ans,sum);
		return ;
	}
	if(c1<(n/2))
	{
		dfs(x+1,sum+a[x][1],c1+1,c2,c3);
	}
	if(c2<(n/2))
	{
		dfs(x+1,sum+a[x][2],c1,c2+1,c3);
	}
	if(c3<(n/2))
	{
		dfs(x+1,sum+a[x][3],c1,c2,c3+1);
	}
	return ;
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
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0ll,0,0,0);
		cout<<ans;
		cout<<'\n';
	}
//	cout<<'\n'<<"多组数据要换行&初始化"; 
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
	return 0;
}
//struct 
