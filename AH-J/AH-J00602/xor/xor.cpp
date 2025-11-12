#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
struct node
{
	int l,r;
}c[1000005];
int dp[500005][2];
bool cmp(node x,node y)
{
	if(x.r==y.r)
		return x.l<y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	/*if(k==0||k==1)
	{
		for(int i=1,x;i<=n;i++)
		{
			cin>>x;
			if(x==k)
				s++;
		}
		cout<<s;
		return 0;
	}
	if(n<=1000)
	{
		int d=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				if((b[i]^b[j-1])==k)
					c[++d]={j,i};
		//cout<<d<<endl;
		int j=0;
		for(int i=1;i<=d;i++)
		{
			while(c[j+1].r<c[i].l)
				j++;
			dp1[i][0]=max(dp1[i-1][0],dp1[i-1][1]);
			dp1[i][1]=dp1[j][1]+1;
			//cout<<dp1[i][0]<<" "<<dp1[i][1]<<endl;
		}
		cout<<max(dp1[d][1],dp1[d][0]);
		return 0;
	}*/
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=b[i-1]^a[i];
	int d=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((b[i-1]^b[j])==k)
			{
				c[++d]={i,j};
				break;
			}
	sort(c+1,c+d+1,cmp);
	int j=0;
	for(int i=1;i<=d;i++)
	{
		while(c[j+1].r<c[i].l)
			j++;
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=dp[j][1]+1;
		//cout<<dp1[i][0]<<" "<<dp1[i][1]<<endl;
	}
	cout<<max(dp[d][1],dp[d][0]);
	return 0;
}
