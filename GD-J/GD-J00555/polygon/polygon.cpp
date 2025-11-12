#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005];
long long ans;
const int mod=998244353;
/*int slove(int x)
{
	int tmp=0,ts[5005];
	memset(ts,0,sizeof(ts));ts[1]=x-1;
	for(int i=2;i<=(x+1)/2;i++)ts[i]=(x-i+1)*(x-i)/2*(x-i)/2+(x-i)-(x-i)/2;
}*/
void dfs(int x,int s,int cnt)
{
	if(x==n+1)return ;
	if(a[x]<s)ans++,ans%=mod;
	dfs(x+1,s+a[x],cnt+1);
	dfs(x+1,s,cnt);
}
int main()//Ô¤¼Æ40pts
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0);cout<<ans%mod;
	return 0;
}
//4 3 2 1

//3 2 1
//2 1
//1

//6 5 4 3 2 1

//5 4 3 2 1
//4 3 2 1
//3 2 1
//2 1
//1


