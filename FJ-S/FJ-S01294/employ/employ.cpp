#include<bits/stdc++.h>
using namespace std;
const int MAXN=510;
int n,m,c[MAXN],a[MAXN],ans;
bool dif[MAXN];
void dfs(int now)
{
	if(now==n)
	{
		int lea=0,pass=0;
		for(int i=1;i<=n;i++)
		{
			if(dif[i]==0||lea>=c[a[i]])lea++;
			else pass++;
		}
		if(pass>=m)ans++;	
		return ;
	}
	for(int i=now;i<=n;i++)
		swap(a[now],a[i]),
		dfs(now+1),
		swap(a[now],a[i]);
}
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	//ovo qwq awa
	//我要上迷惑行为大赏 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
		char c;
		cin>>c;
		dif[i]=(c=='1');
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
