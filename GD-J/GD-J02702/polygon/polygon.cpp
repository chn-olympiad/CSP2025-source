#include<bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
#define ll long long
#define endl "\n"
using namespace std;
const int mod=998244353;
int n,a[5005],maxa;
ll ans; 
ll f[5005][5005];//前i个数大于j的组合数
void init()
{
	sort(a+1,a+n+1);
	for(int j=0;j<=maxa;j++)
	{
		if(a[1]>j)f[1][j]=1;
		else break;
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],maxa=max(maxa,a[i]);
	init();
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=maxa;j++)
		{
			f[i][j]=f[i-1][max(0,j-a[i])]+f[i-1][j]+(a[i]>j);//选a[i]和不选a[i] 
			f[i][j]%=mod;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=maxa;j++)
//		{
//			cout<<f[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=3;i<=n;i++)
	{
		ans+=f[i-1][a[i]];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
