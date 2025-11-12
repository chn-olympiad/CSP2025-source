#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll lt[1<<21];
ll a[N],s[N],dp[N];
ll n,k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=(s[i-1]^a[i]);
	for(int i=0;i<(1<<20);i++) lt[i]=-1;
	lt[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(lt[s[i]^k]<0) dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[lt[s[i]^k]]+1);
		lt[s[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
/*
//freopen
//freopen
froepen
freoepn
#include<bits\stdc++.h> 
x0 y0 x1 y1
signed main() 
*/
