#include<bits/stdc++.h>
using namespace std;
const int N=1000000010;
int dis[10010][10010];
bool w[10010][10010];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans;
	cin>>n>>m>>k;
	if(k==0) {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dis[i][j]=N;
		for(int i=1; i<=m; i++) {
			int a,b,c;
			cin>>a>>b>>c;
			dis[a][b]=c;
			dis[b][a]=dis[a][b];
		}
		for(int i=2; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(dis[1][i]+dis[i][j]<=dis[1][j]) {
					dis[1][j]=dis[1][i]+dis[i][j];
					if(w[1][i]==1)
						ans+=dis[1][i];
						if(w[i][j]==1)
						ans+=dis[i][j];
						w[1][i]=1;
						w[i][j]=1;
				}


			}
		}
		int sum=0;
		for(int i=2;i<=n;i++)
		{
			sum+=dis[1][i];
		}
		cout<<sum-ans<<endl;
	}
}
