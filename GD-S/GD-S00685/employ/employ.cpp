#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
//Ren5Jie4Di4Ling5%
long long n,m,ans;
string a;
long long c[1010];
long long f[1010];
bool bj[1010];
void DFS(long long k,long long tc)
{
	if(n-tc<m) return;
	if(k==n)
	{
		if(n-tc>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!bj[i])
		{
			bj[i]=true;
			f[k+1]=i;
			long long p=0;
			if(c[i]<=tc||a[k]=='0') p=1;
			DFS(k+1,tc+p);
			bj[i]=false;
		}
	}
}
int main(){
	freopen("employ4.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]); 
	if(n==m)
	{
		bool f=true;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='0')
			{
				f=false;
				break;
			}
		}
		cout<<f;
		return 0;
	}
	DFS(0,0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
