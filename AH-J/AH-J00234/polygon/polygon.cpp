#include<bits/stdc++.h>
using namespace std;
int const N=10005;
int a[N],b[N];
int vis[N][N];
int n,mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int ans=0;
	cin>>n;
	b[0]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	
	//for(int i=1;i<=n;i++) cout<<b[i]<<endl;
	for(int i=3;i<=n;i++)//zushu
		for(int l=1;l<=n-i+1;l++)
			for(int j=l+i-1;j<=n;j++)
			{
				//cout<<j<<" "<<l<<" "<<b[j]-b[l-1]<<" "<<a[j]<<endl;
				if(b[j]-b[l-1]>(a[j]*2)&&vis[l][j]==0) 
				{ 
					//cout<<j<<" "<<l<<" "<<b[j]-b[l-1]<<" "<<a[j]<<endl;
					ans=(ans+1)%mod;
					vis[l][j]=1;
				}
			}
	cout<<ans<<endl;
	return 0;
}
