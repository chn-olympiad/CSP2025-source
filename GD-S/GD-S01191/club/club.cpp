#include<bits/stdc++.h>
using namespace std;
const int N=205;
int t,n,a,b,c,f[N][N],ans;
void solve(){
	cin>>n;
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			f[i+1][j+1]=-1e9;
	f[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		for(int j=n/2;j>=0;j--)
		{
			for(int k=n/2;k>=0;k--)
			{
				f[j+1][k+1]+=a;
				if(j)f[j+1][k+1]=max(f[j+1][k+1],f[j][k+1]+b);
				if(k)f[j+1][k+1]=max(f[j+1][k+1],f[j+1][k]+c);
			}
		}
	}
	ans=0;
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			if(n-i-j<=n/2)ans=max(ans,f[i+1][j+1]);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}
