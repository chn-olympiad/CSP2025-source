#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N][3];
int n;
int ans=0;
int a[N][3],b[3];
int dfs(int t)
{
	if(t>n) return 0;
	int temp=0;
	for(int i=0;i<3;i++)
	{
		if(b[i]+1>n/2) continue;
		else{
		b[i]++;
		temp=max(temp,dfs(t+1)+a[t][i]);
		b[i]--;
	    }
	}
	return temp;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    ans=0;
	    int t=n;
	    memset(dp,0,sizeof(dp));
	    memset(b,0,sizeof(b));
	    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	    cout<<dfs(1)<<endl;
	    
    }
    return 0;
}
