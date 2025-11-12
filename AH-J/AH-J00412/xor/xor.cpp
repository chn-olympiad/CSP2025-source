#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
struct node
{
	long long x,y,z;
};
long long ans,n,k,a[N],xr[N];
queue<node>q;
void dp(long long l,long long r,long long m)
{
	long long p=r-l+1;
	for(long long len=m;len<=p;len++){
		for(long long i=l;i+len-1<=r;i++){
			long long j=i+len-1;
			if((xr[j]^xr[i-1])==k){
				ans++;
				if(i-l>len)q.push({l,i-1,len+1});
				if(r-j>=len)q.push({j+1,r,len});
				return;
			}
		}
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		xr[i]=xr[i-1]^a[i];
	}
	q.push({1,n,1});
	long long l,r,m;
	while(!q.empty()){
		l=q.front().x,r=q.front().y,m=q.front().z;
		dp(l,r,m);
		q.pop();
	}
	cout<<ans;
	return 0;
}
/*
 #include<bits/stdc++.h>
using namespace std;
const long long N=1e3+10;
struct node
{
	long long x,y,z;
};
long long ans,n,k,a[N],xr[N],dp[N][N];
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		xr[i]=xr[i-1]^a[i];
	}
	for(long long len=1;len<=n;len++){
		for(long long i=1;i+len-1<=n;i++){
			long long j=i+len-1;
			if((xr[j]^xr[i-1])==k){
				dp[i][j]=1;
			}
			for(long long k=i;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
*/
