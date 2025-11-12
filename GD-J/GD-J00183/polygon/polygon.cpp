#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD=998244353;
int a[5003],n;
ll ans=0;

bool cmp(int a,int b)
{
	return a>b;
}

void dfs(int x,int y,int z)
{
	for(int ii=x+1;ii<=n;ii++)
	{
		y+=a[ii];
		if(y>z*2)
		{
			ans++;
			dfs(ii,y,z);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	
	if(n==3)
	{
		int tot=a[1]+a[2]+a[3];
		if(a[1]*2<tot&&a[2]*2<tot&&a[3]*2<tot) cout<<1;
		else cout<<0;
		return 0;
	}
	
	sort(a+1,a+n+1,cmp);
	
	
	
	for(i=1;i<=n-2;i++) dfs(i,0,i);
	
	cout<<ans%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
