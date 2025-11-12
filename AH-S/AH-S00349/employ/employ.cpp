#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[505];
int a[505],vis[505];
int n,m;
string s;
int ans;
bool check()
{
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		int p=a[i];
		if(s[i-1]=='1' && c[p]>cnt1) cnt2++;
		else cnt1++;
	}
	return cnt2>=m;
}
void dfs(int p)
{
	if(p>n)
	{
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			a[p]=i;
			vis[i]=1;
			dfs(p+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	cin>>s;
	int cnt1=0,cnt2=n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(s[i-1]=='1') cnt1++;
		if(c[i]==0) cnt2--;
	}
	if(cnt1<m || cnt2<m){cout<<0<<endl;return 0;}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
