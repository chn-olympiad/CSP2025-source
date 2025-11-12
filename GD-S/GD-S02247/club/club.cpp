#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
int n,a[N][3],t;
int b[3];
long long dp[N][N];
long long dfs(int step,long long number)
{
	if(step==n) return number;
	long long v[3]={number,number,number};
	if(b[0]<n/2) b[0]++,v[0]=dfs(step+1,number+a[step+1][0]),b[0]--;
	if(b[1]<n/2) b[1]++,v[1]=dfs(step+1,number+a[step+1][1]),b[1]--;
	if(b[2]<n/2) b[2]++,v[2]=dfs(step+1,number+a[step+1][2]),b[2]--;
	return max(v[0],max(v[1],v[2]));
}
void exe()
{
	b[0]=b[1]=b[2]=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
//	long long dp[][]
	
	cout<<dfs(0,0)<<endl;
}


int main()
{
	freopen("club.in","r",stdin);
//	freopen("club2.out","w",stdout);
	cin>>t;
	while(t--) exe();
	return 0;
}

