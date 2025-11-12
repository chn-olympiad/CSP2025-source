#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e4;
const int C=998244353;
int arr[N];
int G[N][N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	if(n==1)cout<<0;
	if(n==2)cout<<0;
	if(n==3)
	{
		int a,b,c;cin>>a>>b>>c;
		int maxn=max(a,max(b,c));
		if(a+b+c>maxn*2)cout<<1;
		else cout<<0;
	}
	else
	{
		vector<int>vect;
		for(int i=0;i<n;i++)
		{
			int x;cin>>x;
			vect.push_back(x);
		}
		for(int i=1;i<=n;i++)G[i][i]=i%C;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				G[i][j]=((G[i][j-1]%C)*(j%C))%C;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//				cout<<G[i][j]<<" ";
//			cout<<endl;
//		}
		int res=0;
		for(int i=3;i<=n;i++)
		{
			res=(res+G[n-i+1][n]/G[1][i])%C;
		}
		cout<<res;
	}
 } 
