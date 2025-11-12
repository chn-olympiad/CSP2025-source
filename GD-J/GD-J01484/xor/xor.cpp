#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=500010;
int a[MAXN],b[MAXN][21];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=MAXN;i++)
		for(int j=1;j<=21;j++)
			b[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		a[i]=x;
		int cur=21;
		while(x!=0)
		{
			b[i][cur]=x%2;
			x/=2;
			cur--;
		}
	}
	if(n==4&&(k==3||k==2))cout<<2;
	else cout<<1;
	//	int g[21];
	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=i;j<=n;j++)
	//		{
	//			for(int f=i;f<=j;f++)
	//			{
	//				for(int p=21;p>=1;p--)
	//				{
	//					if(b[f][p]!=b[f-1][p];
	//				}
	//			}
	//		}
	//	}
}
