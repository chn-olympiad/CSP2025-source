#include<bits/stdc++.h>
using namespace std;
#define int long long
const signed mod=998244353;
int n,a[5005],ans,C[5005][5005],f[5005];
void dfs(int now,int maxnum,int size,int nownum)
{
	int fl=0;
	if(nownum>maxnum*2 && size>=3 && now==n+1 ){
	    ans++,ans%=mod;
	    fl=1;
	}
	if(now==n+1)return;
	dfs(now+1,max(maxnum,a[now]),size+1,nownum+a[now]);
	dfs(now+1,maxnum,size,nownum);
}
signed main()
{
	ios::sync_with_stdio(false);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	int maxa=-1e10;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	if(maxa==1) //ai==1
	{
		f[0]=1;
		f[1]=1;
		for(int i=2;i<=n;i++) f[i]=((f[i-1]%mod)*(i%mod))%mod;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				C[i][j] =(f[i] / (f[j]*f[i-j]) ) %mod;
			}
		}
		int anss=0;
		for(int i=3;i<=n;i++) {
			anss+=C[n][i];
			anss%=mod;
		}
		cout<<(anss+mod*10)%mod<<endl;
	}
	else//n<=20
	{
		dfs(1,0,0,0);
		cout<<ans<<endl;
	 } 
	return 0;
}
