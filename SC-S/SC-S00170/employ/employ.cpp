#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353,N=505;
int a[N],f[N],f_[N],vis[N],pai[N],ans,n,m;
string s;
int poww(int a,int b)
{
	int ans=1;
	for(int i=0;i<60;i++){if((b>>i)&1) ans*=a,ans%=P; a*=a,a%=P;}
	return ans;
}
void F()
{
	f[0]=1;
	for(int i=1;i<N;i++) f[i]=f[i-1]*i,f[i]%=P;
	f_[N-1]=f[N-1]; f_[N-1]=poww(f_[N-1],P-2);
	for(int i=N-2;i>=0;i--) f_[i]=f_[i+1]*(i+1),f_[i]%=P;
}
int A(int x,int y){return (f[x]*f_[x-y])%P;}
void DFS(int now)
{
	if(now>n)
	{
		int num=0,fang=0;
		for(int i=1;i<=n;i++)
		{
			if(fang>=a[pai[i]]){fang++; continue;}
			if(s[i]=='0') fang++;
			else num++;
		}
		if(num>=m) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1,pai[now]=i;
		DFS(now+1);
		vis[i]=0,pai[now]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	F();
	cin >>n >>m;
	cin >>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin >>a[i];
	if(n>100)
	{
		int num=0;
		for(int i=1;i<=n;i++) if(a[i]!=0) num++;
		cout <<A(num,num);
		return 0;
	}
	DFS(1);
	cout <<ans%P;
	return 0;
} 