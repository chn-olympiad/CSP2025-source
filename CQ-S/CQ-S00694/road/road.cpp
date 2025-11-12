#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k,ans;
int f[10100][10100],h[50][10100],s[50];
int dp[10100][10100];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k) ;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		f[a][b]=c;
	}
	int a=1;
	for(int i=1;i<=k;i++){
		cin>>s[i];
		for(int j=1;j<=n;j++){
			cin>>h[i][j];
			h[i][j]+=s[i];
			if(h[i][j]) a=0;
		}
	}
	if(a){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) {
			int minn=1e9;
			for(int kk=1;kk<=k;kk++){
				minn=min(minn,h[kk][i]+h[kk][j]-s[kk]);
			}
			for(int kk=1;kk<=n;kk++){
				if(f[kk][j]&&f[kk][i]){
					cout<<f[kk][i]<<" "<<f[kk][j]<<endl;
					minn=min(minn,f[kk][i]+f[kk][j]);
				}
			}
			if(f[i][j]) ans+=min(minn,f[i][j]);
			else ans+=f[i][j];
		}
	}
	printf("%d",ans);
	return 0;
}
