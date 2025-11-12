#include<bits/stdc++.h>
using namespace std;
const int N=205;
int dp[N][N][N];
struct node{int a,b,c;};
vector<node> a,b,c;
bool cmp(node a,node b){return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _; cin >>_;
	while(_--)
	{
		int n; cin >>n;
		if(n<=200){
		for(int j=0;j<N;j++) for(int k=0;k<N;k++) for(int l=0;l<N;l++) dp[j][k][l]=-2e9;
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,z; cin >>x >>y >>z;
			for(int j=n/2;j>=0;j--) for(int k=n/2;k>=0;k--) for(int l=n/2;l>=0;l--)
			{
				if(j!=0) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+x);
				if(k!=0) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+y);
				if(l!=0) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+z);
			}
		}
		int ans=-2e9;
		for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++) ans=max(ans,dp[i][j][n-i-j]);
		cout <<ans <<'\n';
		}
		else{
		a.clear(),b.clear(),c.clear();
		for(int i=1;i<=n;i++)
		{
			int x,y,z; cin >>x >>y >>z;
			node p; p.a=x,p.b=y,p.c=z;
			int maxx=max(x,max(y,z));
			if(maxx==p.a) a.push_back(p);
			else if(maxx==p.b) b.push_back(p);
			else if(maxx==p.c) c.push_back(p);
		}
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		sort(c.begin(),c.end(),cmp);
		if(a.size()>n/2)
		{
			for(int i=n/2;i<a.size();i++)
			{
				if(a[i].b>a[i].c) b.push_back(a[i]);
				else c.push_back(a[i]);
			}
		}
		if(b.size()>n/2)
		{
			for(int i=n/2;i<b.size();i++)
			{
				if(b[i].a>b[i].c) a.push_back(b[i]);
				else c.push_back(b[i]);
			}
		}
		if(c.size()>n/2)
		{
			for(int i=n/2;i<c.size();i++)
			{
				if(c[i].b>c[i].a) b.push_back(c[i]);
				else a.push_back(c[i]);
			}
		}
		int ans=0;
		int al=a.size(),bl=b.size(),cl=c.size();
		for(int i=0;i<min(n/2,al);i++) ans+=a[i].a;
		for(int i=0;i<min(n/2,bl);i++) ans+=b[i].b;
		for(int i=0;i<min(n/2,cl);i++) ans+=c[i].c;
		cout <<ans <<'\n';
		}
	}
	return 0;
} 