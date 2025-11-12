#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int t,n,a[N][4],MAX,up,vis[4],ct[N];
void dfs(int u,int num)
{
	if(u>n)
	{
		if(num>MAX) MAX=num;
		return;
	} 
	for(int i = 1;i<=3;i++)
	{
		if(vis[i]<up)
		{
			vis[i]++;
			dfs(u+1,num+a[u][i]);
			vis[i]--;
		}
	} 
	return;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		memset(vis,0,sizeof vis);
		cin >> n;
		if(n<=20)
		{
			up=n/2;
			for(int i = 1;i<=n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
			dfs(1,0);
			cout << MAX << endl;
			MAX=0;
		}
		else
		{
			int b,c;
			for(int i = 0;i<n;i++) cin >> ct[i] >> b >> c;
			sort(ct,ct+n,cmp);
			int sum=0;
			for(int i = 0;i<n/2;i++) sum+=ct[i];
			cout << sum << endl;
		}
	}
	return 0;
}
