#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=25;
const int MOD=998244353;
LL n,cnt;
LL a[N],v[N];
void dfs(int x,int h)
{
	if(x>n)
	{
		if(h<3) return ;
		int maxn=0,sum=0;
		FOR(i,1,h)
		{
			if(v[i]>maxn) maxn=v[i];
			sum+=v[i];
		}
		if(sum>2*maxn) cnt++;
		cnt=cnt%MOD;
		return ;
	}
	dfs(x+1,h);
	v[h+1]=a[x];
	dfs(x+1,h+1);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	FOR(i,1,n) cin>>a[i];
	if(n<=20)
	{
		dfs(1,0);
		cout<<cnt%MOD;
	}
	else
	{
		cnt=1;
		FOR(i,1,n) cnt=(cnt*2)%MOD;
		cout<<(cnt-n-1-(n-1)*n/2+MOD)%MOD;
	}
	return 0;
}
