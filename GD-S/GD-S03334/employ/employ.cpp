#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
//#define int long long
using namespace std;
const int N=1e6+10;
int n,m,c[N],p[N],ans;
string s;
bool vis[N];
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)if(s[i-1]=='1'&&(i-1)-cnt<c[p[i]])cnt++;
	return cnt>=m;
}
void dfs(int x)
{
	if(x>n)
	{
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			p[x]=0;
			vis[i]=0;
		}
	}
}
int main()
{
	fre("employ");
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1);
	cout<<ans;
}

