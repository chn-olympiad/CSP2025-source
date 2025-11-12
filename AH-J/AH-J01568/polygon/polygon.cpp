
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5005,MOD=998244353;
int n;
ll a[N],s,ans;
bool A;

void dfs(int now,ll sum,int m,bool xx)
{
	if(sum>a[m] and xx)
	{
		s++,s%=MOD;
	}
	if(now==m)
		return;
	dfs(now+1,sum+a[now],m,true);
	dfs(now+1,sum,m,false);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	A=true;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			A=false;
	}
	
	if(A)
	{
		s=4;
		for(int i=3;i<=n;i++)
		{
			ans+=s-i;
			ans%=MOD;
			s*=2;
			s%=MOD;
		}
		cout<<ans;
		return 0;
	}
	
	sort(a+1,a+1+n);
	
	for(int i=3;i<=n;i++)
	{
		s=0;
		dfs(1,0,i,true);
		ans+=s;
		ans%=MOD;
	}
	
	cout<<ans;
	
	return 0;
}
