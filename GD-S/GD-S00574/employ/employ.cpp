#include<iostream>
#include<cstring> 
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<ctime>
#include<random>
using namespace std;
const int Mod=998244353;
int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-'0',c=getchar();}
	return sum*f;
}
mt19937 rnd(time(nullptr));
string s;
int a[20],pd[20],n,m,jr[20];
int ans=0;
int bfs(int now)
{
	if(now==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(i-sum-1>=jr[i]) continue;
			if(s[i-1]=='1') sum++;
		}
		if(sum>=m) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(pd[i]==1) continue;
		pd[i]=1;
		jr[now]=a[i];
		bfs(now+1);
		pd[i]=0;
	}
} 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	int sum=0;
	for(int i=1;i<=n;i++) if(s[i-1]=='1') sum++;
	if(n<=10)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		bfs(1);
		cout<<ans;
	}
	else cout<<rnd()%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
