#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int d[N][N],f[N][N];
int a[21][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,K;
	cin>>n>>m>>K;
	memset(d,0x3f,sizeof(d));
	int ans=0x3f3f3f3f;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)d[i][j]=f[i][j];
	if(!K){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(d[i][j]==0x3f3f3f3f)break;
				for(int k=1;k<=n;k++)d[i][k]=min(d[i][k],d[i][j]+d[j][k]);
			}
		cout<<d[1][n];
		return 0;	
	}
	for(int i=1;i<=K;i++)
		for(int j=0;j<=n;j++)cin>>a[i][j];
	int x=pow(2,K);
	for(int c=0;c<=x;c++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)d[i][j]=f[i][j];
		int cnt=0;
		int t=c;
		string s;
		while(t){
			s+=char(t%2+48);
			t/=2;
		}
		while(s.size()<K)s+='0';
		reverse(s.begin(),s.end());
		for(int id=0;id<K;id++){
			if(s[id]=='1')cnt+=a[id][0];
			else continue;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],a[id][i]+a[id][j]);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(d[i][j]==0x3f3f3f3f)break;
				for(int k=1;k<=n;k++)d[i][k]=min(d[i][k],d[i][j]+d[j][k]);
			}
		for(int i=1;i<n;i++)
			if(d[i][i+1]==0x3f3f3f3f)continue;
		ans=min(ans,cnt+d[1][n]);
	}
	cout<<ans;
}
